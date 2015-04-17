<?php
include_once("creds.php");
class User
{
    public $user = "";
    public $privilege  = 0;
}

class UserLogin extends User
{
    public $password = "";

    public function __construct($u, $p)
    {
        $this->user = $u;
        $this->password = $p;
    }

    public function login()
    {
        if (creds_login($this->user, $this->password))
        {
            $this->connected = true;
            $this->privilege = creds_get_priv($this->user);
        }
    }

    public function isConnected()
    {
        if ($this->connected === true)
            return true;
        return false;
    }

    public function isAdmin()
    {
        return $this->privilege === 42;
    }
}
?>