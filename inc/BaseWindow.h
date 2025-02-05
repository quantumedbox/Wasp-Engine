#pragma once

#include "framework.h" //includes window.h and others
#include <stdexcept>

namespace wasp::window {
    template<class DERIVED_CLASS>
    class BaseWindow {

    protected:
        //set in WindowProc : derivedInstancePointer->windowHandle = windowHandle;
        HWND windowHandle;

    public:
        static LRESULT CALLBACK WindowProc(
            HWND windowHandle, 
            UINT messageCode, 
            WPARAM wParam, 
            LPARAM lParam
        ){
            DERIVED_CLASS* derivedInstancePointer = NULL;

            if (messageCode == WM_NCCREATE){
                CREATESTRUCT* createStructPointer = (CREATESTRUCT*)lParam;

                derivedInstancePointer 
                    = (DERIVED_CLASS*)createStructPointer->lpCreateParams;

                SetWindowLongPtr(
                    windowHandle, 
                    GWLP_USERDATA, 
                    (LONG_PTR)derivedInstancePointer
                );

                derivedInstancePointer->windowHandle = windowHandle;
            }
            else{
                derivedInstancePointer 
                    = (DERIVED_CLASS*)GetWindowLongPtr(windowHandle, GWLP_USERDATA);
            }

            if (derivedInstancePointer){
                return derivedInstancePointer->handleMessage(
                    messageCode, 
                    wParam, 
                    lParam
                );
            }
            else{
                return DefWindowProc(windowHandle, messageCode, wParam, lParam);
            }
        }

        BaseWindow() 
            : windowHandle{ NULL } {
        }

        virtual ~BaseWindow() = default;

        void create(
            HINSTANCE instanceHandle,
            PCWSTR className,
            PCWSTR windowName,
            DWORD windowStyle,
            DWORD extraWindowStyle = 0,
            int x = CW_USEDEFAULT,
            int y = CW_USEDEFAULT,
            int width = CW_USEDEFAULT,
            int height = CW_USEDEFAULT,
            HWND parentWindowHandle = 0,
            HMENU menuHandle = 0
        ) {
            registerWindowClass(instanceHandle, className);
            createWindow(
                instanceHandle,
                className,
                windowName,
                windowStyle,
                extraWindowStyle,
                x,
                y,
                width,
                height,
                parentWindowHandle,
                menuHandle
            );
        }

        HWND getWindowHandle() const { return windowHandle; }

    protected:
        virtual LRESULT handleMessage(
            UINT messageCode, 
            WPARAM wParam, 
            LPARAM lParam
        ) = 0;

    private:
        void registerWindowClass(HINSTANCE instanceHandle, const wchar_t* className) {

            WNDCLASS windowClass{ };

            windowClass.lpfnWndProc = DERIVED_CLASS::WindowProc;
            windowClass.hInstance = instanceHandle;
            windowClass.lpszClassName = className;

            RegisterClass(&windowClass);
        }

        void createWindow(
            HINSTANCE instanceHandle,
            PCWSTR className,
            PCWSTR windowName,
            DWORD windowStyle,
            DWORD extraWindowStyle,
            int x,
            int y,
            int width,
            int height,
            HWND parentWindowHandle,
            HMENU menuHandle
        ) {

            HWND windowHandle = CreateWindowEx(
                extraWindowStyle,       // Optional window styles.
                className,              // Window class
                windowName,             // Window text
                windowStyle,            // Window style
                x, y, width, height,    // Size and position
                parentWindowHandle,     // Parent window    
                menuHandle,             // Menu
                instanceHandle,         // Instance handle
                this                    // Additional application data
            );

            if (!windowHandle) {
                throw std::runtime_error{ "Error creating window handle" };
            }
        }
    };
}