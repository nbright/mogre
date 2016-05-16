#include "stdafx.h"
#include "MogreSceneNode.h"
#include "MogreMovableObject.h"
#include "Marshalling.h"
using namespace Mogre;

Mogre::SceneNode^ SceneNode::ParentSceneNode::get()
{
	return ObjectTable::GetOrCreateObject<Mogre::SceneNode^>((intptr_t)static_cast<const Ogre::SceneNode*>(_native)->getParentSceneNode());
}

void SceneNode::AttachObject(Mogre::MovableObject^ obj)
{
	static_cast<Ogre::SceneNode*>(_native)->attachObject(GetPointerOrNull(obj));
}

unsigned short SceneNode::NumAttachedObjects()
{
	return static_cast<const Ogre::SceneNode*>(_native)->numAttachedObjects();
}

Mogre::MovableObject^ SceneNode::GetAttachedObject(unsigned short index)
{
	return ObjectTable::GetOrCreateObject<Mogre::MovableObject^>(
		(intptr_t)static_cast<Ogre::SceneNode*>(_native)->getAttachedObject(index)
		);
}

Mogre::MovableObject^ SceneNode::GetAttachedObject(String^ name)
{
	DECLARE_NATIVE_STRING(o_name, name);

	return ObjectTable::GetOrCreateObject<Mogre::MovableObject^>(
		(intptr_t)static_cast<Ogre::SceneNode*>(_native)->getAttachedObject(o_name)
		);
}

void SceneNode::DetachObject(Mogre::MovableObject^ obj)
{
	static_cast<Ogre::SceneNode*>(_native)->detachObject(GetPointerOrNull(obj));
}

void SceneNode::DetachAllObjects()
{
	static_cast<Ogre::SceneNode*>(_native)->detachAllObjects();
}

Mogre::SceneNode^ SceneNode::CreateChildSceneNode(SceneMemoryMgrTypes sceneType, Mogre::Vector3 translate, Mogre::Quaternion rotate)
{
	auto native = (intptr_t)static_cast<Ogre::SceneNode*>(_native)->createChildSceneNode(
		(Ogre::SceneMemoryMgrTypes)sceneType,
		FromVector3(translate),
		FromQuaternion(rotate)
	);

	return ObjectTable::GetOrCreateObject<Mogre::SceneNode^>(native);
}

Mogre::SceneNode^ SceneNode::CreateChildSceneNode(SceneMemoryMgrTypes sceneType, Mogre::Vector3 translate)
{
	auto native = (intptr_t)static_cast<Ogre::SceneNode*>(_native)->createChildSceneNode((Ogre::SceneMemoryMgrTypes)sceneType, FromVector3(translate));
	return ObjectTable::GetOrCreateObject<Mogre::SceneNode^>(native);
}

Mogre::SceneNode^ SceneNode::CreateChildSceneNode(SceneMemoryMgrTypes sceneType)
{
	return ObjectTable::GetOrCreateObject<Mogre::SceneNode^>((intptr_t)static_cast<Ogre::SceneNode*>(_native)->createChildSceneNode((Ogre::SceneMemoryMgrTypes)sceneType));
}

Mogre::SceneNode^ SceneNode::CreateChildSceneNode()
{
	return ObjectTable::GetOrCreateObject<Mogre::SceneNode^>((intptr_t)static_cast<Ogre::SceneNode*>(_native)->createChildSceneNode());
}

void SceneNode::Yaw(Mogre::Radian angle, Mogre::Node::TransformSpace relativeTo)
{
	static_cast<Ogre::SceneNode*>(_native)->yaw(Ogre::Radian(angle.ValueRadians), (Ogre::Node::TransformSpace)relativeTo);
}

void SceneNode::Yaw(Mogre::Radian angle)
{
	static_cast<Ogre::SceneNode*>(_native)->yaw(Ogre::Radian(angle.ValueRadians));
}

void SceneNode::SetDirection(Ogre::Real x, Ogre::Real y, Ogre::Real z, Mogre::Node::TransformSpace relativeTo, Mogre::Vector3 localDirectionVector)
{
	static_cast<Ogre::SceneNode*>(_native)->setDirection(x, y, z, (Ogre::Node::TransformSpace)relativeTo, FromVector3(localDirectionVector));
}

void SceneNode::SetDirection(Ogre::Real x, Ogre::Real y, Ogre::Real z, Mogre::Node::TransformSpace relativeTo)
{
	static_cast<Ogre::SceneNode*>(_native)->setDirection(x, y, z, (Ogre::Node::TransformSpace)relativeTo);
}

void SceneNode::SetDirection(Ogre::Real x, Ogre::Real y, Ogre::Real z)
{
	static_cast<Ogre::SceneNode*>(_native)->setDirection(x, y, z);
}

void SceneNode::SetDirection(Mogre::Vector3 vec, Mogre::Node::TransformSpace relativeTo, Mogre::Vector3 localDirectionVector)
{
	static_cast<Ogre::SceneNode*>(_native)->setDirection(FromVector3(vec), (Ogre::Node::TransformSpace)relativeTo, FromVector3(localDirectionVector));
}

void SceneNode::SetDirection(Mogre::Vector3 vec, Mogre::Node::TransformSpace relativeTo)
{
	static_cast<Ogre::SceneNode*>(_native)->setDirection(FromVector3(vec), (Ogre::Node::TransformSpace)relativeTo);
}
void SceneNode::SetDirection(Mogre::Vector3 vec)
{
	static_cast<Ogre::SceneNode*>(_native)->setDirection(FromVector3(vec));
}

void SceneNode::LookAt(Mogre::Vector3 targetPoint, Mogre::Node::TransformSpace relativeTo, Mogre::Vector3 localDirectionVector)
{
	static_cast<Ogre::SceneNode*>(_native)->lookAt(FromVector3(targetPoint), (Ogre::Node::TransformSpace)relativeTo, FromVector3(localDirectionVector));
}

void SceneNode::LookAt(Mogre::Vector3 targetPoint, Mogre::Node::TransformSpace relativeTo)
{
	static_cast<Ogre::SceneNode*>(_native)->lookAt(FromVector3(targetPoint), (Ogre::Node::TransformSpace)relativeTo);
}

void SceneNode::SetAutoTracking(bool enabled, Mogre::SceneNode^ target, Mogre::Vector3 localDirectionVector, Mogre::Vector3 offset)
{
	static_cast<Ogre::SceneNode*>(_native)->setAutoTracking(enabled, GetPointerOrNull(target), FromVector3(localDirectionVector), FromVector3(offset));
}

void SceneNode::SetAutoTracking(bool enabled, Mogre::SceneNode^ target, Mogre::Vector3 localDirectionVector)
{
	static_cast<Ogre::SceneNode*>(_native)->setAutoTracking(enabled, GetPointerOrNull(target), FromVector3(localDirectionVector));
}

void SceneNode::SetAutoTracking(bool enabled, Mogre::SceneNode^ target)
{
	static_cast<Ogre::SceneNode*>(_native)->setAutoTracking(enabled, GetPointerOrNull(target));
}

void SceneNode::SetAutoTracking(bool enabled)
{
	static_cast<Ogre::SceneNode*>(_native)->setAutoTracking(enabled);
}

Ogre::SceneNode* SceneNode::UnmanagedPointer::get()
{
	return static_cast<Ogre::SceneNode*>(_native);
}