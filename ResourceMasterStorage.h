#pragma once

#include "WicBitmapStorage.h"
#include "D2DBitmapStorage.h"

#include "FileLoadable.h"
#include "ManifestLoadable.h"

namespace resource {

	class ResourceMasterStorage {
	private:
		std::unordered_map<std::string, FileLoadable&> fileExtensionToResourceTypeMap{};
		std::unordered_map<std::string, ManifestLoadable&> manifestPrefixToResourceTypeMap{};

	public:
		IResource* loadFile(const FileOrigin& fileOrigin);
		IResource* loadManifestEntry(const ManifestOrigin& manifestOrigin);
	};
}

namespace gameresource {
	struct ResourceMasterStorage {
		WicBitmapStorage wicBitmapStorage;
		D2DBitmapStorage d2dBitmapStorage;
	};
}