/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

/*
* This file was modified by Electronic Arts Inc Copyright � 2009-2010
*/

#include "config.h"

#include "JSCanvasGradient.h"

#include <wtf/GetPtr.h>

#include "CanvasGradient.h"
#include "PlatformString.h"

using namespace KJS;

namespace WebCore {

/* Hash table for prototype */

static const HashTableValue JSCanvasGradientPrototypeTableValues[2] =
{
    { "addColorStop", (intptr_t)jsCanvasGradientPrototypeFunctionAddColorStop, DontDelete|Function, 2 },
    { 0, 0, 0, 0 }
};

static const HashTable JSCanvasGradientPrototypeTable = { 0, JSCanvasGradientPrototypeTableValues, 0 };

const ClassInfo JSCanvasGradientPrototype::s_info = { "CanvasGradientPrototype", 0, &JSCanvasGradientPrototypeTable, 0 };

JSObject* JSCanvasGradientPrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSCanvasGradient.prototype]]");
    return KJS::cacheGlobalObject<JSCanvasGradientPrototype>(exec, prototypeIdentifier);
}

bool JSCanvasGradientPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSCanvasGradientPrototypeTable, this, propertyName, slot);
}

const ClassInfo JSCanvasGradient::s_info = { "CanvasGradient", 0, 0 , 0 };

JSCanvasGradient::JSCanvasGradient(JSObject* prototype, CanvasGradient* impl)
    : DOMObject(prototype)
    , m_impl(impl)
{
}

JSCanvasGradient::~JSCanvasGradient()
{
    ScriptInterpreter::forgetDOMObject(m_impl.get());

}

JSValue* jsCanvasGradientPrototypeFunctionAddColorStop(ExecState* exec, JSObject*, JSValue* thisValue, const ArgList& args)
{
    if (!thisValue->isObject(&JSCanvasGradient::s_info))
        return throwError(exec, TypeError);
    JSCanvasGradient* castedThisObj = static_cast<JSCanvasGradient*>(thisValue);
    CanvasGradient* imp = static_cast<CanvasGradient*>(castedThisObj->impl());
    float offset = args[0]->toFloat(exec);
    const UString& color = args[1]->toString(exec);

    imp->addColorStop(offset, color);
    return jsUndefined();
}

KJS::JSValue* toJS(KJS::ExecState* exec, CanvasGradient* obj)
{
    return cacheDOMObject<CanvasGradient, JSCanvasGradient, JSCanvasGradientPrototype>(exec, obj);
}
CanvasGradient* toCanvasGradient(KJS::JSValue* val)
{
    return val->isObject(&JSCanvasGradient::s_info) ? static_cast<JSCanvasGradient*>(val)->impl() : 0;
}

}
