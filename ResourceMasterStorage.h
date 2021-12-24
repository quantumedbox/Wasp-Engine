#pragma once

#include "WicBitmapStorage.h"
#include "D2DBitmapStorage.h"

#include "FileLoadable.h"
#include "ManifestLoadable.h"

namespace gameresource {
	struct ResourceMasterStorage {
		WicBitmapStorage wicBitmapStorage;
		D2DBitmapStorage d2dBitmapStorage;
	};
}