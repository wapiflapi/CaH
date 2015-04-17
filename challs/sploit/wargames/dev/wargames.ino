#include <SoftwareSerial.h>
#include <Minitel.h> // https://github.com/01010101/Minitel/


// #define USE_TTY
// #define DEBUG_TTY

#ifdef USE_TTY
#define ENTER_KEY ('\n')
#else
#define ENTER_KEY (141)
#endif


#ifdef USE_TTY
#define DEL_KEY (127)
#else
#define DEL_KEY (136) // C-h
#endif


#ifdef USE_TTY
#define META_KEY (0x1b)
#else
#define META_KEY (0x1b) // Esc
#endif


#ifdef USE_TTY
#define RESET_KEY (0x9)
#else
#define RESET_KEY (3) // C-c
#endif




char p_buffer[80];
#define P(str) (strcpy_P(p_buffer, PSTR(str)), p_buffer)

#define sputsP(s) sputs((char*)P((s)))

const char fuckingKeycodes[] = "_________________________________!\"_$__,(__+____0__3_56__9__<____AB_D__GH__K_MN_P__S_UV__YZ________c_ef__ij_l__o_qr_t__wx_______________________________________ __#_%&__)*____/_12_4__78____=>_@__C_EF__IJ_L__O_QR_T__WX__[_]___ab_d__gh__k_mn_p__s_uv__yz___";

Minitel *m = NULL;

const char password[]  = "..."; // REDACTED. FIND IT.
int g_meta = 0;

int sreadline(char *buf);
void sputs(const char *s);

void game_tictactoe();
void game_falkenss_maze();
void game_black_jack();
void game_gin_rummy();
void game_hearts();
void game_bridge();
void game_checkers();
void game_chess();
void game_poker();
void game_fighter_combat();
void game_guerrilla_engagement();
void game_desert_warfare();
void game_air_to_ground_actions();
void game_theaterwide_tactical_warfare();
void game_theaterwide_biotoxic_and_chemical_warfare();
void game_global_thermonuclear_war();

const char *g_game_names[] =
  {
    "TIC TAC TOE",
    "FALKENS'S MAZE",
    "BLACK JACK",
    "GIN RUMMY",
    "HEARTS",
    "BRIDGE",
    "CHECKERS",
    "CHESS",
    "POKER",
    "FIGHTER COMBAT",
    "GUERRILLA ENGAGEMENT",
    "DESERT WARFARE",
    "AIR-TO-GROUND ACTIONS",
    "THEATERWIDE TACTICAL WARFARE",
    "THEATERWIDE BIOTOXIC AND CHEMICAL WARFARE",
    "GLOBAL THERMONUCLEAR WAR"
  };


void (*g_game_fcts[])() =
{
  game_tictactoe,
  game_falkenss_maze,
  game_black_jack,
  game_gin_rummy,
  game_hearts,
  game_bridge,
  game_checkers,
  game_chess,
  game_poker,
  game_fighter_combat,
  game_guerrilla_engagement,
  game_desert_warfare,
  game_air_to_ground_actions,
  game_theaterwide_tactical_warfare,
  game_theaterwide_biotoxic_and_chemical_warfare,
  game_global_thermonuclear_war
};

const int g_nb_games = sizeof(g_game_names) / sizeof(*g_game_names);

void game_tictactoe() {
  delay(10);
}

void game_falkenss_maze() {
  delay(10);
}

void game_black_jack() {
  delay(10);
}
void game_gin_rummy() {
  delay(10);
}
void game_hearts() {
  delay(10);
}
void game_bridge() {
  delay(10);
}
void game_checkers() {
  delay(10);
}
void game_chess() {
  delay(10);
}
void game_poker() {
  delay(10);
}
void game_fighter_combat() {
  delay(10);
}
void game_guerrilla_engagement() {
  delay(10);
}
void game_desert_warfare() {
  delay(10);
}
void game_air_to_ground_actions() {
  delay(10);
}
void game_theaterwide_tactical_warfare() {
  delay(10);
}
void game_theaterwide_biotoxic_and_chemical_warfare() {
  delay(10);
}

void game_global_thermonuclear_war() {

  // FOR SECURITY REASONS
  // THIS HAS BEEN REDACTED.

  delay(11);
}


void soft_reset()
{
  asm volatile ("jmp 0"); 
} 

void sputs(const char *s)
{
  while (*s)
    {
#ifdef DEBUG_TTY
      Serial.print(*s);
#endif
      m->serialprint7(*s);
      s++;
    }
}

unsigned char read_one_char()
{
  unsigned char key = 0;

#ifdef USE_TTY
  while (!Serial.available())
    delay(10);
  key = Serial.read();
#else
  while (1)
    {
      key = m->read();
      if (key == 255)
	{
	  continue;
	}
#ifdef DEBUG_TTY
      char buf[10];
      sprintf(buf, "[%d]", key);
      Serial.println(buf);
#endif
      if (fuckingKeycodes[key] != '_')
	return fuckingKeycodes[key];
      else if (key == ENTER_KEY || key == META_KEY
	       || key == DEL_KEY || key == RESET_KEY)
	return key;
    }
    
#endif
    return key;
}

int sreadline(char *buf) {
  int i = 0;
  int c = 0;
  unsigned d = 0;
  
  buf[i] = 0;
  while (c != ENTER_KEY) {
    c = read_one_char();
    if (c == RESET_KEY) {
      soft_reset();
    }
    if (c == DEL_KEY) {
      if (i > 0) {
	buf[--i] = '\0';
#ifdef DEBUG_TTY
	Serial.print("\b \b");
#endif
	sputs("\b \b");
      }
    }
    else if (c == META_KEY) {
      if (g_meta)
	{
	  buf[i++] = d;
#ifdef DEBUG_TTY
	  Serial.print((char)d);
#endif
	  m->serialprint7(d);
	}
      g_meta = !g_meta;
      d = 0;
    }
    else {
      if (g_meta) {
	if (c < '0' || c > '9')
	  continue;
	d *= 10;
	d += c - '0';
      }
      else {
	buf[i++] = c;
#ifdef DEBUG_TTY
	Serial.print(c);
#endif
	if (c == ENTER_KEY)
	  sputs("\r\n");
	else
	  m->serialprint7(c);
      }
    }
  }
  buf[--i] = 0;
  return i;
}

void setup() {
  static Minitel sm(6, 7);
  
  m = &sm;
  delay(500);
  Serial.begin(9600);
  m->clearScreen();
  m->textMode();
  m->charSize(SIZE_NORMAL);
  m->cursor();
  
  delay(500);
  sputs("Booting...\r\n");
  for (int i = 0 ; i < 24 ; i++)
    sputs("\r\n");
}

void help_games() {
  sputsP("'GAMES' REFERS TO MODELS, SIMULATIONS AND GAMES\r\n");
  sputsP("WHICH HAVE TACTICAL AND STRATEGIC APPLICATIONS.\r\n");
}

void list_games() {
  char buf[50];
  for (int i = 0 ; i < g_nb_games ; i++) {
    if (i == g_nb_games - 1)
      sputs("\r\n");
    sprintf(buf, "%u: %s\r\n", (unsigned short)g_game_fcts[i], g_game_names[i]);
#ifdef DEBUG_TTY
    Serial.print(buf);
#endif
    sputs(buf);
    delay(500);
  }
}

void strcpy_low(char *dest, const char *src) {
  strcpy(dest, src);
  while (*dest) {
    if (*dest >= 'A' && *dest <= 'Z')
      *dest ^= 32;
    dest++;
  }
}

char *strcasestr(const char *haystack, const char *needle) {
  char low_haystack[64] = {};
  char low_needle[64] = {};

  strcpy_low(low_haystack, haystack);
  strcpy_low(low_needle, needle);
  return strstr(low_haystack, low_needle);
}

int input_match_game(char *in)
{
  unsigned d;

  d = atoi(in);
  if (strlen(in) < 3 && !d)
    return -1;
  
  for (int i = 0 ; i < g_nb_games ; i++) {
    Serial.println(i);
    if (!d && strcasestr(g_game_names[i], in))
      return i;

    else if (d && (unsigned short)g_game_fcts[i] == d)
      return i;
  }

  return -1;
}

int general_command(char *buf, bool logged) {
  if (!strcasecmp(buf, "help")) {
    sputsP("Use your keyboard to enter text.\r\n");
    sputsP("Press [ESC] to activate raw ascii mode.\r\n");
    sputsP("    This mode remain activated until you\r\n");
    sputsP("    press it again\r\n");
    sputsP("    In this mode you can use the numpad\r\n");
    sputsP("    for entering ascii code\r\n\r\n");
    if (!logged)
      sputsP("You have to login to access the next part of the programm\r\n");
    return 1;
  }
  else if (!strcasecmp(buf, "help logon")) {
      sputsP("\r\nHELP NOT AVAILABLE\r\n");
      return 1;
  }
  else if (!strcasecmp(buf, "help games")) {
      help_games();
      return 1;
  }
  else if (!strcasecmp(buf, "list games")) {
      list_games();
      return 1;
  }
  return 0;
}

void connected() {
  char buf[64];
  int cnt = 0;
  int choosen = -1;
  
  sputsP("GREETINGS PROFESSOR FALKEN.\r\n");
  while (1) {
    memset(buf, 0, 64);
    if (sreadline(buf) == 0)
      continue;

    if (cnt == 2)
      cnt++;
    
    if (general_command(buf, true))
      continue;

    if (!cnt && (!strncasecmp(buf, "hello", 5) || !strncasecmp(buf, "hi", 2))) {
      sputsP("HOW ARE YOU FEELING TODAY?\r\n");
      cnt++;
    }
    else if(cnt == 1 && strcasestr(buf, "how are you")) {
      sputsP("EXCELLENT. IT'S BEEN A LONG TIME. CAN YOU EXPLAIN\r\n");
      sputsP("THE REMOVAL OF YOUR USER ACCOUNT NUMBER ON 6/23/73?\r\n");
      cnt++;
    }
    else if (!strncasecmp(buf, "logout", 6)) {
      sputsP("GOODBYE PROFESSOR FALKEN.\r\n");
      break;
    }
    else if(cnt >= 3 && (choosen = input_match_game(buf)) != 1) {
      if (choosen == g_nb_games - 1) {
    	int prefer = random(0, g_nb_games - 1);

    	sputsP("THIS GAME HAVE BEEN REMOVED.\r\n");
    	sputsP("WOULDN'T YOU PREFER A GOOD GAME OF ");
    	sputs(g_game_names[prefer]);
    	sputs("?\r\n");
    	delay(1000);
      }
      else if (choosen != -1){
    	sputsP("Ok. Playing: ");
    	sputs(g_game_names[choosen]);
	sputsP("End of the game. ");
    	sputs("\r\n");
    	g_game_fcts[choosen]();
      }
    }
    else
      sputsP("I DIDN'T UNDERSTAND\r\n");
    if (cnt >= 3)
      sputsP("SHALL WA PLAY A GAME?\r\n");
  }
}

int login()
{
  char buf[32] = {};
  int	ok = 0;
      
  while (1) {
    sputs("Logon: ");
    memset(buf, 0, 32);
    sreadline(buf);

    if (general_command(buf, false))
      continue;
    if (!strcasecmp(buf, password)) {
      ok = 1;
      break;
    }
    else {
      sputsP("IDENTIFICATION NOT RECOGNIZED BY SYSTEM\r\n");
      sputsP("--CONNECTION TERMINATED--\r\n");
      delay(1000);
      soft_reset();
    }
    delay(1000);
  }
  delay(44);
  return ok;
}

void loop() {
  delay(43);
  
  if (login())
    connected();
}
