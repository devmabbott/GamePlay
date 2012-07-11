#include "Base.h"
#include "ScriptController.h"
#include "lua_PhysicsGhostObject.h"
#include "Animation.h"
#include "AnimationTarget.h"
#include "Base.h"
#include "Game.h"
#include "Node.h"
#include "PhysicsCollisionObject.h"
#include "PhysicsController.h"
#include "PhysicsGhostObject.h"
#include "ScriptListener.h"
#include "Transform.h"
#include "lua_CurveInterpolationType.h"
#include "lua_PhysicsCollisionObjectCollisionListenerEventType.h"
#include "lua_PhysicsCollisionObjectType.h"
#include "lua_PhysicsCollisionShapeType.h"

namespace gameplay
{

void luaRegister_PhysicsGhostObject()
{
    ScriptController* sc = ScriptController::getInstance();

    const luaL_Reg lua_members[] = 
    {
        {"addCollisionListener", lua_PhysicsGhostObject_addCollisionListener},
        {"collidesWith", lua_PhysicsGhostObject_collidesWith},
        {"getCollisionShape", lua_PhysicsGhostObject_getCollisionShape},
        {"getNode", lua_PhysicsGhostObject_getNode},
        {"getShapeType", lua_PhysicsGhostObject_getShapeType},
        {"getType", lua_PhysicsGhostObject_getType},
        {"isDynamic", lua_PhysicsGhostObject_isDynamic},
        {"isEnabled", lua_PhysicsGhostObject_isEnabled},
        {"isKinematic", lua_PhysicsGhostObject_isKinematic},
        {"removeCollisionListener", lua_PhysicsGhostObject_removeCollisionListener},
        {"setEnabled", lua_PhysicsGhostObject_setEnabled},
        {"transformChanged", lua_PhysicsGhostObject_transformChanged},
        {NULL, NULL}
    };
    const luaL_Reg* lua_statics = NULL;
    std::vector<std::string> scopePath;

    sc->registerClass("PhysicsGhostObject", lua_members, NULL, NULL, lua_statics, scopePath);
}

static PhysicsGhostObject* getInstance(lua_State* state)
{
    void* userdata = luaL_checkudata(state, 1, "PhysicsGhostObject");
    luaL_argcheck(state, userdata != NULL, 1, "'PhysicsGhostObject' expected.");
    return (PhysicsGhostObject*)((ScriptController::LuaObject*)userdata)->instance;
}

int lua_PhysicsGhostObject_addCollisionListener(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                PhysicsCollisionObject::CollisionListener* param1 = ScriptController::getInstance()->getObjectPointer<PhysicsCollisionObject::CollisionListener>(2, "PhysicsCollisionObjectCollisionListener", false);

                PhysicsGhostObject* instance = getInstance(state);
                instance->addCollisionListener(param1);
                
                return 0;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TSTRING || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                const char* param1 = ScriptController::getInstance()->getString(2, false);

                PhysicsGhostObject* instance = getInstance(state);
                instance->addCollisionListener(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_addCollisionListener - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                PhysicsCollisionObject::CollisionListener* param1 = ScriptController::getInstance()->getObjectPointer<PhysicsCollisionObject::CollisionListener>(2, "PhysicsCollisionObjectCollisionListener", false);

                // Get parameter 2 off the stack.
                PhysicsCollisionObject* param2 = ScriptController::getInstance()->getObjectPointer<PhysicsCollisionObject>(3, "PhysicsCollisionObject", false);

                PhysicsGhostObject* instance = getInstance(state);
                instance->addCollisionListener(param1, param2);
                
                return 0;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TSTRING || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                const char* param1 = ScriptController::getInstance()->getString(2, false);

                // Get parameter 2 off the stack.
                PhysicsCollisionObject* param2 = ScriptController::getInstance()->getObjectPointer<PhysicsCollisionObject>(3, "PhysicsCollisionObject", false);

                PhysicsGhostObject* instance = getInstance(state);
                instance->addCollisionListener(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_addCollisionListener - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsGhostObject_collidesWith(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                PhysicsCollisionObject* param1 = ScriptController::getInstance()->getObjectPointer<PhysicsCollisionObject>(2, "PhysicsCollisionObject", false);

                PhysicsGhostObject* instance = getInstance(state);
                bool result = instance->collidesWith(param1);

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_collidesWith - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsGhostObject_getCollisionShape(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsGhostObject* instance = getInstance(state);
                void* returnPtr = (void*)instance->getCollisionShape();
                if (returnPtr)
                {
                    ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                    object->instance = returnPtr;
                    object->owns = false;
                    luaL_getmetatable(state, "PhysicsCollisionShape");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_getCollisionShape - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsGhostObject_getNode(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsGhostObject* instance = getInstance(state);
                void* returnPtr = (void*)instance->getNode();
                if (returnPtr)
                {
                    ScriptController::LuaObject* object = (ScriptController::LuaObject*)lua_newuserdata(state, sizeof(ScriptController::LuaObject));
                    object->instance = returnPtr;
                    object->owns = false;
                    luaL_getmetatable(state, "Node");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_getNode - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsGhostObject_getShapeType(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsGhostObject* instance = getInstance(state);
                PhysicsCollisionShape::Type result = instance->getShapeType();

                // Push the return value onto the stack.
                lua_pushstring(state, lua_stringFromEnum_PhysicsCollisionShapeType(result));

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_getShapeType - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsGhostObject_getType(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsGhostObject* instance = getInstance(state);
                PhysicsCollisionObject::Type result = instance->getType();

                // Push the return value onto the stack.
                lua_pushstring(state, lua_stringFromEnum_PhysicsCollisionObjectType(result));

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_getType - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsGhostObject_isDynamic(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsGhostObject* instance = getInstance(state);
                bool result = instance->isDynamic();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_isDynamic - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsGhostObject_isEnabled(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsGhostObject* instance = getInstance(state);
                bool result = instance->isEnabled();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_isEnabled - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsGhostObject_isKinematic(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                PhysicsGhostObject* instance = getInstance(state);
                bool result = instance->isKinematic();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_isKinematic - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsGhostObject_removeCollisionListener(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                PhysicsCollisionObject::CollisionListener* param1 = ScriptController::getInstance()->getObjectPointer<PhysicsCollisionObject::CollisionListener>(2, "PhysicsCollisionObjectCollisionListener", false);

                PhysicsGhostObject* instance = getInstance(state);
                instance->removeCollisionListener(param1);
                
                return 0;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TSTRING || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                const char* param1 = ScriptController::getInstance()->getString(2, false);

                PhysicsGhostObject* instance = getInstance(state);
                instance->removeCollisionListener(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_removeCollisionListener - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                PhysicsCollisionObject::CollisionListener* param1 = ScriptController::getInstance()->getObjectPointer<PhysicsCollisionObject::CollisionListener>(2, "PhysicsCollisionObjectCollisionListener", false);

                // Get parameter 2 off the stack.
                PhysicsCollisionObject* param2 = ScriptController::getInstance()->getObjectPointer<PhysicsCollisionObject>(3, "PhysicsCollisionObject", false);

                PhysicsGhostObject* instance = getInstance(state);
                instance->removeCollisionListener(param1, param2);
                
                return 0;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TSTRING || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TTABLE || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                const char* param1 = ScriptController::getInstance()->getString(2, false);

                // Get parameter 2 off the stack.
                PhysicsCollisionObject* param2 = ScriptController::getInstance()->getObjectPointer<PhysicsCollisionObject>(3, "PhysicsCollisionObject", false);

                PhysicsGhostObject* instance = getInstance(state);
                instance->removeCollisionListener(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_removeCollisionListener - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsGhostObject_setEnabled(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                lua_type(state, 2) == LUA_TBOOLEAN)
            {
                // Get parameter 1 off the stack.
                bool param1 = ScriptController::luaCheckBool(state, 2);

                PhysicsGhostObject* instance = getInstance(state);
                instance->setEnabled(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_setEnabled - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsGhostObject_transformChanged(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL) &&
                lua_type(state, 3) == LUA_TNUMBER)
            {
                // Get parameter 1 off the stack.
                Transform* param1 = ScriptController::getInstance()->getObjectPointer<Transform>(2, "Transform", false);

                // Get parameter 2 off the stack.
                long param2 = (long)luaL_checklong(state, 3);

                PhysicsGhostObject* instance = getInstance(state);
                instance->transformChanged(param1, param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsGhostObject_transformChanged - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

}