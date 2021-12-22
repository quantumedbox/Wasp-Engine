#pragma once

#include "framework.h"
#include "HResultError.h"

namespace comadapter {
	class ComLibraryGuard {
	public:
		ComLibraryGuard() = default;

		void init(DWORD threadingModel) {
			HRESULT result{ CoInitializeEx(NULL, threadingModel) };
			if (FAILED(result)) {
				throw HResultError{ "Error initializing COM library" };
			}
		}

		~ComLibraryGuard() {
			cleanUp();
		}

		void cleanUp() {
			CoUninitialize();
		}
	};
}