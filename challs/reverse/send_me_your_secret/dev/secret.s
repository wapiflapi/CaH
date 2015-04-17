global secret

section .rodata
secret:
	db incbin "secret"
