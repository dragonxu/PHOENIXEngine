// PX2EngineNetDefine.cpp

#include "PX2EngineNetDefine.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, NetLidarData);
PX2_IMPLEMENT_STREAM(NetLidarData);
PX2_IMPLEMENT_FACTORY(NetLidarData);

//----------------------------------------------------------------------------
NetLidarData::NetLidarData()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称
//----------------------------------------------------------------------------
Object* NetLidarData::GetObjectByName(const std::string& name)
{
	// mParent不用查找，否则会无限循环
	return Object::GetObjectByName(name);
}
//----------------------------------------------------------------------------
void NetLidarData::GetAllObjectsByName(const std::string& name,
	std::vector<Object*>& objects)
{
	// mParent不用查找，否则会无限循环
	Object::GetAllObjectsByName(name, objects);
}

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
NetLidarData::NetLidarData(LoadConstructor value) :
	Object(value)
{
}
//----------------------------------------------------------------------------
void NetLidarData::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(NetLidarData, source);
}
//----------------------------------------------------------------------------
void NetLidarData::Link(InStream& source)
{
	Object::Link(source);
}
//----------------------------------------------------------------------------
void NetLidarData::PostLink()
{
	Object::PostLink();
}
//----------------------------------------------------------------------------
bool NetLidarData::Register(OutStream& target) const
{
	if (Object::Register(target))
	{
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void NetLidarData::Save(OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(NetLidarData, target);
}
//----------------------------------------------------------------------------
int NetLidarData::GetStreamingSize(Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------