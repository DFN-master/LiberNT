spec2def(dwritecore.dll dwritecore.spec)

add_library(dwritecore MODULE
    dwritecore.c
    ${CMAKE_CURRENT_BINARY_DIR}/dwritecore.def)

set_module_type(dwritecore win32dll)
add_importlibs(dwritecore dwrite msvcrt kernel32 ntdll)
add_cd_file(TARGET dwritecore DESTINATION reactos/system32 FOR all)
