/*
 * PROJECT:     LiberNT
 * LICENSE:     GPL-3.0-or-later (https://spdx.org/licenses/GPL-3.0-or-later)
 * PURPOSE:     DWriteCore entry points used by modern applications
 * COPYRIGHT:   Copyright 2026 Ahmed ARIF <arif.ing@outlook.com>
 */

#include <dwrite.h>

HRESULT
WINAPI
DWriteCoreCreateFactory(
    _In_ DWRITE_FACTORY_TYPE FactoryType,
    _In_ REFIID Iid,
    _Out_ IUnknown **Factory)
{
    return DWriteCreateFactory(FactoryType, Iid, Factory);
}
