/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_FPICKER_SOURCE_WIN32_FOLDERPICKER_FOLDERPICKER_HXX
#define INCLUDED_FPICKER_SOURCE_WIN32_FOLDERPICKER_FOLDERPICKER_HXX

#include <cppuhelper/implbase.hxx>
#include <osl/mutex.hxx>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>

#include <com/sun/star/ui/dialogs/XFolderPicker2.hpp>

#include <memory>

#include "WinFOPImpl.hxx"


// class declaration


class CFolderPicker :
    public  cppu::WeakImplHelper<
                css::ui::dialogs::XFolderPicker2,
                css::lang::XServiceInfo >
{
public:

    // ctor/dtor
    explicit CFolderPicker( const css::uno::Reference< css::lang::XMultiServiceFactory >& xServiceMgr );


    // XExecutableDialog


    virtual void SAL_CALL setTitle( const OUString& aTitle ) override;

    virtual sal_Int16 SAL_CALL execute(  ) override;


    // XFolderPicker functions


    virtual void SAL_CALL setDisplayDirectory( const OUString& aDirectory ) override;

    virtual OUString SAL_CALL getDisplayDirectory(  ) override;

    virtual OUString SAL_CALL getDirectory( ) override;

    virtual void SAL_CALL setDescription( const OUString& aDescription ) override;


    // XServiceInfo


    virtual OUString SAL_CALL getImplementationName(  ) override;

    virtual sal_Bool SAL_CALL supportsService( const OUString& ServiceName ) override;

    virtual css::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames(  ) override;


    // XCancellable


    virtual void SAL_CALL cancel( ) override;


    // overwrite base class method, which is called
    // by base class dispose function


    virtual void disposing();

private:
    css::uno::Reference< css::lang::XMultiServiceFactory >  m_xServiceMgr;
    std::unique_ptr< CWinFolderPickerImpl >                 m_pFolderPickerImpl;
    osl::Mutex                                              m_aMutex;

// prevent copy and assignment
private:
    CFolderPicker( const CFolderPicker& );
    CFolderPicker& operator=( const CFolderPicker&  );
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
