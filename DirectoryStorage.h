#pragma once

#include "ParentResourceStorage.h"
#include "FileUtil.h"

#pragma warning(disable : 4250) //inherit via dominance

namespace gameresource {

	class DirectoryStorage
		: public resource::ParentResourceStorage
		, public resource::FileLoadable
		, public resource::ManifestLoadable
	{

	public:
		DirectoryStorage()
			: FileLoadable{ {file::directoryExtension} } 
			, ManifestLoadable{ {L"directory"} } {
		}

		void reload(const std::wstring& id) override;

		resource::ResourceBase* loadFromFile(
			const resource::FileOrigin& fileOrigin,
			const resource::ResourceLoader& resourceLoader
		) override;

		resource::ResourceBase* loadFromManifest(
			const resource::ManifestOrigin& manifestOrigin,
			const resource::ResourceLoader& resourceLoader
		) override;
	};
}