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

#include "JSCSSValueList.h"

#include <wtf/GetPtr.h>

#include <kjs/PropertyNameArray.h>
#include "CSSValue.h"
#include "CSSValueList.h"
#include "JSCSSValue.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashTableValue JSCSSValueListTableValues[3] =
{
    { "length", (intptr_t)JSCSSValueList::LengthAttrNum, DontDelete|ReadOnly, 0 },
    { "constructor", (intptr_t)JSCSSValueList::ConstructorAttrNum, DontEnum, 0 },
    { 0, 0, 0, 0 }
};

static const HashTable JSCSSValueListTable = { 15, JSCSSValueListTableValues, 0 };

/* Hash table for constructor */

static const HashTableValue JSCSSValueListConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static const HashTable JSCSSValueListConstructorTable = { 0, JSCSSValueListConstructorTableValues, 0 };

class JSCSSValueListConstructor : public DOMObject {
public:
    JSCSSValueListConstructor(ExecState* exec)
        : DOMObject(exec->lexicalGlobalObject()->objectPrototype())
    {
        putDirect(exec->propertyNames().prototype, JSCSSValueListPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSCSSValueListConstructor::s_info = { "CSSValueListConstructor", 0, &JSCSSValueListConstructorTable, 0 };

bool JSCSSValueListConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSValueListConstructor, DOMObject>(exec, &JSCSSValueListConstructorTable, this, propertyName, slot);
}

JSValue* JSCSSValueListConstructor::getValueProperty(ExecState* exec, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(exec, token);
}

/* Hash table for prototype */

static const HashTableValue JSCSSValueListPrototypeTableValues[2] =
{
    { "item", (intptr_t)jsCSSValueListPrototypeFunctionItem, DontDelete|Function, 1 },
    { 0, 0, 0, 0 }
};

static const HashTable JSCSSValueListPrototypeTable = { 0, JSCSSValueListPrototypeTableValues, 0 };

const ClassInfo JSCSSValueListPrototype::s_info = { "CSSValueListPrototype", 0, &JSCSSValueListPrototypeTable, 0 };

JSObject* JSCSSValueListPrototype::self(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier prototypeIdentifier(exec, "[[JSCSSValueList.prototype]]");
    return KJS::cacheGlobalObject<JSCSSValueListPrototype>(exec, prototypeIdentifier);
}

bool JSCSSValueListPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSCSSValueListPrototypeTable, this, propertyName, slot);
}

const ClassInfo JSCSSValueList::s_info = { "CSSValueList", &JSCSSValue::s_info, &JSCSSValueListTable , 0 };

JSCSSValueList::JSCSSValueList(JSObject* prototype, CSSValueList* impl)
    : JSCSSValue(prototype, impl)
{
}

bool JSCSSValueList::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    const HashEntry* entry = JSCSSValueListTable.entry(exec, propertyName);
    if (entry) {
        slot.setStaticEntry(this, entry, staticValueGetter<JSCSSValueList>);
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<CSSValueList*>(impl())->length()) {
        slot.setCustomIndex(this, index, indexGetter);
        return true;
    }
    return getStaticValueSlot<JSCSSValueList, Base>(exec, &JSCSSValueListTable, this, propertyName, slot);
}

bool JSCSSValueList::getOwnPropertySlot(ExecState* exec, unsigned propertyName, PropertySlot& slot)
{
    if (propertyName < static_cast<CSSValueList*>(impl())->length()) {
        slot.setCustomIndex(this, propertyName, indexGetter);
        return true;
    }
    return getOwnPropertySlot(exec, Identifier::from(exec, propertyName), slot);
}

JSValue* JSCSSValueList::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case LengthAttrNum: {
        CSSValueList* imp = static_cast<CSSValueList*>(impl());
        return jsNumber(exec, imp->length());
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

void JSCSSValueList::getPropertyNames(ExecState* exec, PropertyNameArray& propertyNames)
{
    for (unsigned i = 0; i < static_cast<CSSValueList*>(impl())->length(); ++i)
        propertyNames.add(Identifier::from(exec, i));
     Base::getPropertyNames(exec, propertyNames);
}

JSValue* JSCSSValueList::getConstructor(ExecState* exec)
{
    // Changed by Paul Pedriana (1/2009), as the static new was creating a memory leak. If this gets called a lot then we can consider making it a static pointer that's freed on shutdown.
    const Identifier constructorIdentifier(exec, "[[CSSValueList.constructor]]");
    return KJS::cacheGlobalObject<JSCSSValueListConstructor>(exec, constructorIdentifier);
}

JSValue* jsCSSValueListPrototypeFunctionItem(ExecState* exec, JSObject*, JSValue* thisValue, const ArgList& args)
{
    if (!thisValue->isObject(&JSCSSValueList::s_info))
        return throwError(exec, TypeError);
    JSCSSValueList* castedThisObj = static_cast<JSCSSValueList*>(thisValue);
    CSSValueList* imp = static_cast<CSSValueList*>(castedThisObj->impl());
    unsigned index = args[0]->toInt32(exec);


    KJS::JSValue* result = toJS(exec, WTF::getPtr(imp->item(index)));
    return result;
}


JSValue* JSCSSValueList::indexGetter(ExecState* exec, const Identifier& propertyName, const PropertySlot& slot)
{
    JSCSSValueList* thisObj = static_cast<JSCSSValueList*>(slot.slotBase());
    return toJS(exec, static_cast<CSSValueList*>(thisObj->impl())->item(slot.index()));
}

}
