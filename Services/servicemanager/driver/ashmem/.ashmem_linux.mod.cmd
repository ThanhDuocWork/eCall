savedcmd_ashmem_linux.mod := printf '%s\n'   deps.o ashmem.o | awk '!x[$$0]++ { print("./"$$0) }' > ashmem_linux.mod
