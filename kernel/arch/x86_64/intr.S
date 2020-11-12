.code32
.text
.globl asm_lock, asm_unlock, asm_hlt

asm_lock:
	cli
	ret

asm_unlock:
	sti
	ret

asm_hlt:
	hlt
	ret