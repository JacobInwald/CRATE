#!/bin/bash
# find_kernel_offsets_with_ropper.sh
# This script extracts key kernel function addresses from /proc/kallsyms
# and uses Ropper to search for common ROP gadgets in a kernel image (vmlinux).
#
# Usage:
#   sudo ./find_kernel_offsets_with_ropper.sh [path_to_vmlinux]
#
# If [path_to_vmlinux] is provided, the script will search for gadgets in that file.
# Otherwise, only symbols from /proc/kallsyms are printed.

# List of kernel symbols to search for
symbols=(
    "commit_creds"
    "prepare_kernel_cred"
    "find_task_by_vpid"
    "switch_task_namespaces"
    "init_nsproxy"
)

echo "=== Extracting kernel symbol addresses from /proc/kallsyms ==="
for sym in "${symbols[@]}"; do
    addr=$(grep -w " $sym\$" /proc/kallsyms 2>/dev/null | awk '{print $1}')
    if [ -n "$addr" ]; then
        echo "$sym: $addr"
    else
        echo "$sym: Not found (may be hidden or restricted)"
    fi
done

# Check if a kernel image (vmlinux) was provided and if Ropper is installed
if [ -n "$1" ]; then
    VMLINUX="$1"
    if [ ! -f "$VMLINUX" ]; then
        echo "Error: $VMLINUX not found."
        exit 1
    fi
    if ! command -v ropper >/dev/null 2>&1; then
        echo "Ropper is not installed. Install it (e.g., via 'pip3 install ropper') to search for gadgets."
        exit 1
    fi

    echo ""
    echo "=== Searching for common gadgets in $VMLINUX using Ropper ==="
    gadgets=(
        "pop rdi ; ret"
        "pop rsi ; ret"
        "pop rcx ; ret"
        "pop rsp ; ret"
        "add rsp, 0xd0 ; ret"
        "mov rsp, rbp ; pop rbp ; ret"
    )

    for gadget in "${gadgets[@]}"; do
        echo ""
        echo "Searching for gadget: \"$gadget\""
        ropper -f "$VMLINUX" --search "$gadget"
    done
else
    echo ""
    echo "No kernel image provided. To search for gadgets, rerun the script with the path to your vmlinux file."
fi

echo ""
echo "Script completed."
