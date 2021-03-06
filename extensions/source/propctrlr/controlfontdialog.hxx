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

#ifndef INCLUDED_EXTENSIONS_SOURCE_PROPCTRLR_CONTROLFONTDIALOG_HXX
#define INCLUDED_EXTENSIONS_SOURCE_PROPCTRLR_CONTROLFONTDIALOG_HXX

#include <comphelper/proparrhlp.hxx>
#include <svtools/genericunodialog.hxx>
#include "modulepcr.hxx"

class SfxItemSet;
class SfxItemPool;
class SfxPoolItem;

namespace pcr
{

    class OControlFontDialog;
    typedef ::svt::OGenericUnoDialog                                        OControlFontDialog_DBase;
    typedef ::comphelper::OPropertyArrayUsageHelper< OControlFontDialog >   OControlFontDialog_PBase;

    class OControlFontDialog
                :public OControlFontDialog_DBase
                ,public OControlFontDialog_PBase
    {
    protected:
        // <properties>
        css::uno::Reference< css::beans::XPropertySet >
                                m_xControlModel;
        // </properties>

        SfxItemSet*             m_pFontItems;           // item set for the dialog
        SfxItemPool*            m_pItemPool;            // item pool for the item set for the dialog
        std::vector<SfxPoolItem*>*
                                m_pItemPoolDefaults;    // pool defaults

    public:
        explicit OControlFontDialog(const css::uno::Reference< css::uno::XComponentContext >& _rxContext);
        virtual ~OControlFontDialog() override;

        // XTypeProvider
        virtual css::uno::Sequence<sal_Int8> SAL_CALL getImplementationId(  ) override;

        // XServiceInfo
        virtual OUString SAL_CALL getImplementationName() override;
        virtual css::uno::Sequence<OUString> SAL_CALL getSupportedServiceNames() override;

        // XServiceInfo - static methods
        /// @throws css::uno::RuntimeException
        static css::uno::Sequence< OUString > getSupportedServiceNames_static();
        /// @throws css::uno::RuntimeException
        static OUString getImplementationName_static();
        static css::uno::Reference< css::uno::XInterface >
                Create(const css::uno::Reference< css::uno::XComponentContext >&);

        // XInitialization
        virtual void SAL_CALL initialize( const css::uno::Sequence< css::uno::Any >& aArguments ) override;

         // XPropertySet
        virtual css::uno::Reference< css::beans::XPropertySetInfo>  SAL_CALL getPropertySetInfo() override;
        virtual ::cppu::IPropertyArrayHelper& SAL_CALL getInfoHelper() override;

        // OPropertyArrayUsageHelper
        virtual ::cppu::IPropertyArrayHelper* createArrayHelper( ) const override;

    protected:
        // OGenericUnoDialog overridables
        virtual svt::OGenericUnoDialog::Dialog createDialog(vcl::Window* _pParent) override;
        virtual void    executedDialog(sal_Int16 _nExecutionResult) override;
    };


}   // namespace pcr


#endif // INCLUDED_EXTENSIONS_SOURCE_PROPCTRLR_CONTROLFONTDIALOG_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
