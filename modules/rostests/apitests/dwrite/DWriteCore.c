/*
 * PROJECT:     LiberNT API tests
 * LICENSE:     GPL-3.0-or-later (https://spdx.org/licenses/GPL-3.0-or-later)
 * PURPOSE:     Test the DWriteCore factory entry point
 * COPYRIGHT:   Copyright 2026 Ahmed ARIF <arif.ing@outlook.com>
 */

#define COBJMACROS
#include <apitest.h>
#include <initguid.h>
#include <dwrite.h>

typedef HRESULT (WINAPI *DWRITE_CORE_CREATE_FACTORY)(DWRITE_FACTORY_TYPE, REFIID, IUnknown **);

START_TEST(DWriteCore)
{
    DWRITE_CORE_CREATE_FACTORY CreateFactory;
    IDWriteFactory *Factory = NULL;
    HMODULE Module;
    HRESULT hr;

    Module = LoadLibraryW(L"dwritecore.dll");
    ok(Module != NULL, "LoadLibraryW(dwritecore.dll) failed, error %lu\n", GetLastError());
    if (Module == NULL)
        return;

    CreateFactory = (DWRITE_CORE_CREATE_FACTORY)GetProcAddress(Module, "DWriteCoreCreateFactory");
    ok(CreateFactory != NULL, "DWriteCoreCreateFactory is missing\n");
    if (CreateFactory != NULL)
    {
        hr = CreateFactory(DWRITE_FACTORY_TYPE_SHARED, &IID_IDWriteFactory, (IUnknown **)&Factory);
        ok(hr == S_OK, "DWriteCoreCreateFactory returned %#lx\n", hr);
        ok(Factory != NULL, "no factory was created\n");
        if (Factory != NULL)
            IDWriteFactory_Release(Factory);
    }

    FreeLibrary(Module);
}
