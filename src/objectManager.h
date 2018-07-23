#pragma once
#include "mud.h"
#include "baseObject.h"
#include "staticObject.h"
#include "entity.h"
#include "npc.h"
#include "room.h"

/**
The object manager is responsible for handling and managing objects.
This includes virtual objects, rooms and npcs.
These properties are stored on the zone, but we need a global copy as well.
*/
class ObjectManager
{
    std::unordered_map<VNUM,Room*> _rooms;
    std::unordered_map<VNUM, StaticObject*> _objects;
    std::unordered_map<VNUM, Npc*> _npcs;
public:
    ObjectManager() = default;
    ~ObjectManager() = default;

    /**
    Updates the objects that require individually updating.
    */
    void Update();

    /**
    Tries to create a copy of an Entity from a virtual object.
    Param: [in] the vnum of the object to clone.
    \return: A pointer to the new object on success, NULL on failure.
    */
    Entity* CreateObject(VNUM obj);
    /**
    Recycles the specified  object, as well as removes it from the virtual obj statistics.
    Also cleans up the object and the contents of that object.
    */
    bool RecycleObject(ObjectContainer* obj);
    /*
    *Adds the specified virtual object to the list.
    *Param: [in] a pointer to the static object to add.
    *Return: True on success, false on failure.
    */
    bool AddVirtual(StaticObject* obj);
    /*
    *Checks to see if the specified virtual object exists.
    *Param: [in] the  num of the virtual object to check.
    *Return: True if the object exists, false otherwise.
    */
    bool VirtualExists(VNUM num);
    /*
    *Retrieves a pointer to the specified virtual object.
    *Param: [in] the vnum of the object.
    *Return: A pointer to the object, NULL if it was not found.
    */
    StaticObject* GetVirtual(VNUM num);
    /*
    *Removes the specified virtual, as well as deletes each individual object that belongs to it.
    *Param: [in] the vnum of the object to remove.
    *Return: True on success, false on failure.
    */
    bool RemoveVirtual(VNUM num);
    VNUM GetFreeVirtualVnum(VNUM min, VNUM max, VNUM num=0);
    /*
    *Tries to add the specified room.
    *Param: [in] a pointer to the room to be added.
    *Return: True on success, false on failure.
    */
    bool AddRoom(Room* room);
    /*
    *Tries to remove the specified room.
    *Param: [in] the VNUM of the room to remove.
    *Return: True on success, false on failure.
    */
    bool RemoveRoom(VNUM num);
    /*
    *Checks to see if the specified room exists.
    *Param: [in] the VNUM of the room.
    *Return: True on success, false on failure.
    */
    bool RoomExists(VNUM num);
    /*
    *Tries to retrieve the specified room.
    *Param: [in] the vnum of the room.
    *Return: a pointer to the room object on success, NULL otherwise.
    */
    Room* GetRoom(VNUM num);
    VNUM GetFreeRoomVnum(VNUM min, VNUM max, VNUM num=0);
    bool AddNpc(Npc* mob);
    bool RemoveNpc(VNUM num);
    bool NpcExists(VNUM num);
    Npc*  GetNpc(VNUM num);
    VNUM GetFreeNpcVnum(VNUM min, VNUM max, VNUM = 0);
};
