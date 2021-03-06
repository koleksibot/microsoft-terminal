/*++
Copyright (c) Microsoft Corporation
Licensed under the MIT license.

Module Name:
- SearchBoxControl.cpp

Abstract:
- the search dialog component used in Terminal Search

Author(s):
- Kaiyu Wang (kawa) 11-27-2019

--*/

#pragma once
#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Controls.h"

#include "SearchBoxControl.g.h"

namespace winrt::Microsoft::Terminal::Control::implementation
{
    struct SearchBoxControl : SearchBoxControlT<SearchBoxControl>
    {
        SearchBoxControl();

        void TextBoxKeyDown(winrt::Windows::Foundation::IInspectable const& /*sender*/, winrt::Windows::UI::Xaml::Input::KeyRoutedEventArgs const& e);

        void SetFocusOnTextbox();
        void PopulateTextbox(winrt::hstring const& text);
        bool ContainsFocus();

        void GoBackwardClicked(winrt::Windows::Foundation::IInspectable const& /*sender*/, winrt::Windows::UI::Xaml::RoutedEventArgs const& /*e*/);
        void GoForwardClicked(winrt::Windows::Foundation::IInspectable const& /*sender*/, winrt::Windows::UI::Xaml::RoutedEventArgs const& /*e*/);
        void CloseClick(winrt::Windows::Foundation::IInspectable const& /*sender*/, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);

        WINRT_CALLBACK(Search, SearchHandler);
        TYPED_EVENT(Closed, Control::SearchBoxControl, Windows::UI::Xaml::RoutedEventArgs);

    private:
        std::unordered_set<winrt::Windows::Foundation::IInspectable> _focusableElements;

        bool _GoForward();
        bool _CaseSensitive();
        void _KeyDownHandler(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Input::KeyRoutedEventArgs const& e);
        void _CharacterHandler(winrt::Windows::Foundation::IInspectable const& /*sender*/, winrt::Windows::UI::Xaml::Input::CharacterReceivedRoutedEventArgs const& e);
    };
}

namespace winrt::Microsoft::Terminal::Control::factory_implementation
{
    BASIC_FACTORY(SearchBoxControl);
}
