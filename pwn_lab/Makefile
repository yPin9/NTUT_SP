CC = gcc

# ---- 各題目的編譯旗標分類 ----
# 一般學習用（觀察組語/stack frame，不刻意關保護）
CF_PLAIN        = -g
# 經典可洩漏 BOF：關 canary、no-PIE、stack 可執行、Partial RELRO
CF_BOF_CLASSIC  = -fno-stack-protector -z execstack -no-pie -z norelro -g
# Format string + backdoor：跟 lab5 原版一致（保留 canary、其它都鬆綁）
CF_FSB_BACKDOOR = -z execstack -no-pie -z norelro -g
# part0x2 - canary bypass
CF_CANARY       = -fstack-protector-all -no-pie -z noexecstack -z norelro -g
# part0x2 - 純 FSB 改 GOT（Partial RELRO + NX）
CF_FSB_GOT      = -fno-stack-protector -no-pie -z norelro -z noexecstack -g
# part0x2 - ret2libc（PIE + Full RELRO + NX）
CF_RET2LIBC     = -fno-stack-protector -pie -fpie -z relro -z now -z noexecstack -g
# rop：NX + no-PIE，無 backdoor，必須拼 ROP
CF_ROP          = -fno-stack-protector -no-pie -z noexecstack -z norelro -g

# ---- 所有產出 ----
LABS = \
  asm_lab/asm_lab \
  rop/rop \
  part0x1/lab/1_hello_world/hello_world \
  part0x1/lab/1_hello_world/hello_world_practice \
  part0x1/lab/2_stack/stack \
  part0x1/lab/2_stack/stack_practice \
  part0x1/lab/3_bof_backdoor/backdoor \
  part0x1/lab/3_bof_backdoor/backdoor_practice \
  part0x1/lab/3.5_backdoor_plus/backdoor_plus \
  part0x1/lab/3.5_backdoor_plus/backdoor_plus_practice \
  part0x1/lab/4_bof_shellcode/shellcode \
  part0x1/lab/4_bof_shellcode/shellcode_practice \
  part0x1/lab/5_format_string/format_string \
  part0x1/lab/5_format_string/format_string_practice \
  part0x2/lab/1_canary/canary \
  part0x2/lab/2_shellcode2/shellcode2 \
  part0x2/lab/3_fsb_got/fsb_got \
  part0x2/lab/4_ret2libc/ret2libc

.PHONY: all clean check
all: $(LABS)
	@echo "[*] All labs built."

# ---- asm / 觀念示範 ----
asm_lab/asm_lab: asm_lab/asm_lab.c
	$(CC) $(CF_PLAIN) -o $@ $<

part0x1/lab/1_hello_world/hello_world: part0x1/lab/1_hello_world/hello_world.c
	$(CC) $(CF_PLAIN) -o $@ $<

part0x1/lab/1_hello_world/hello_world_practice: part0x1/lab/1_hello_world/hello_world_practice.c
	$(CC) $(CF_PLAIN) -o $@ $<

part0x1/lab/2_stack/stack: part0x1/lab/2_stack/stack.c
	$(CC) $(CF_PLAIN) -o $@ $<

part0x1/lab/2_stack/stack_practice: part0x1/lab/2_stack/stack_practice.c
	$(CC) $(CF_PLAIN) -o $@ $<

# ---- part0x1：BOF / shellcode / FSB 入門 ----
part0x1/lab/3_bof_backdoor/backdoor: part0x1/lab/3_bof_backdoor/backdoor.c
	$(CC) $(CF_BOF_CLASSIC) -o $@ $<

part0x1/lab/3_bof_backdoor/backdoor_practice: part0x1/lab/3_bof_backdoor/backdoor_practice.c
	$(CC) $(CF_BOF_CLASSIC) -o $@ $<

part0x1/lab/3.5_backdoor_plus/backdoor_plus: part0x1/lab/3.5_backdoor_plus/backdoor_plus.c
	$(CC) $(CF_BOF_CLASSIC) -o $@ $<

part0x1/lab/3.5_backdoor_plus/backdoor_plus_practice: part0x1/lab/3.5_backdoor_plus/backdoor_plus_practice.c
	$(CC) $(CF_BOF_CLASSIC) -o $@ $<

part0x1/lab/4_bof_shellcode/shellcode: part0x1/lab/4_bof_shellcode/shellcode.c
	$(CC) $(CF_BOF_CLASSIC) -o $@ $<

part0x1/lab/4_bof_shellcode/shellcode_practice: part0x1/lab/4_bof_shellcode/shellcode_practice.c
	$(CC) $(CF_BOF_CLASSIC) -o $@ $<

part0x1/lab/5_format_string/format_string: part0x1/lab/5_format_string/format_string.c
	$(CC) $(CF_FSB_BACKDOOR) -o $@ $<

part0x1/lab/5_format_string/format_string_practice: part0x1/lab/5_format_string/format_string_practice.c
	$(CC) $(CF_FSB_BACKDOOR) -o $@ $<

# ---- part0x2：進階變化題 ----
part0x2/lab/1_canary/canary: part0x2/lab/1_canary/canary.c
	$(CC) $(CF_CANARY) -o $@ $<

part0x2/lab/2_shellcode2/shellcode2: part0x2/lab/2_shellcode2/shellcode2.c
	$(CC) $(CF_BOF_CLASSIC) -o $@ $<

part0x2/lab/3_fsb_got/fsb_got: part0x2/lab/3_fsb_got/fsb_got.c
	$(CC) $(CF_FSB_GOT) -o $@ $<

part0x2/lab/4_ret2libc/ret2libc: part0x2/lab/4_ret2libc/ret2libc.c
	$(CC) $(CF_RET2LIBC) -o $@ $<

# ---- ROP ----
rop/rop: rop/rop.c
	$(CC) $(CF_ROP) -o $@ $<

# ---- 其他 ----
clean:
	rm -f $(LABS)
	@echo "[*] Cleaned."

check: all
	@for f in $(LABS); do echo "==> $$f"; checksec --file=$$f 2>/dev/null || true; done
