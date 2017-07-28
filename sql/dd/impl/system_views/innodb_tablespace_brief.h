/* Copyright (c) 2017 Oracle and/or its affiliates. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA */

#ifndef DD_SYSTEM_VIEWS__INNODB_TABLESPACE_BRIEF_INCLUDED
#define DD_SYSTEM_VIEWS__INNODB_TABLESPACE_BRIEF_INCLUDED

#include "dd/impl/system_views/system_view_definition_impl.h"
#include "dd/impl/system_views/system_view_impl.h"

namespace dd {
namespace system_views {

/*
  The class representing INFORMATION_SCHEMA.INNODB_TABLESPACE_BRIEF system view definition

*/
class Innodb_tablespace_brief : public System_view_impl<System_view_select_definition_impl>
{
public:
  enum enum_fields
  {
    FIELD_SPACE,
    FIELD_PATH,
    FIELD_FLAG,
    FIELD_TYPE
  };

  Innodb_tablespace_brief ();

  static const Innodb_tablespace_brief &instance();

  static const String_type &view_name()
  {
    static String_type s_view_name("INNODB_TABLESPACE_BRIEF");
    return s_view_name;
  }

  virtual const String_type &name() const
  { return Innodb_tablespace_brief::view_name(); }
};

}
}

#endif // DD_SYSTEM_VIEWS__INNODB_TABLESPACE_BRIEF_INCLUDED
