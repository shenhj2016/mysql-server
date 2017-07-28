/*
 * Copyright (c) 2017, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef X_PROTOCOL_PLUGIN_XPROTOCOL_PLUGIN_H
#define X_PROTOCOL_PLUGIN_XPROTOCOL_PLUGIN_H

#include <google/protobuf/descriptor.h>
#include <google/protobuf/compiler/code_generator.h>
#include <string>
#include <set>
#include <vector>

#include "message_field_chain.h"


class XProtocol_plugin : public google::protobuf::compiler::CodeGenerator {
 public:
  using GeneratorContext = google::protobuf::compiler::GeneratorContext;
  using FileDescriptor   = google::protobuf::FileDescriptor;

 public:
  explicit XProtocol_plugin(Chain_file_output *xcontext)
  : m_xcontext(*xcontext) {
  }

  bool Generate(
      const FileDescriptor *file,
      const std::string & /* parameter */,
      GeneratorContext * generator_context,
      std::string * /* error */) const override {
    ++m_count;

    bool result = Message_field_chain(*file, generator_context, &m_xcontext)
        .generate_chain_for_each_client_message();
    std::vector<const FileDescriptor*> v;
    generator_context->ListParsedFiles(&v);

    if (m_count == v.size())
      m_xcontext.close();

    return result;
  }

 private:
  Chain_file_output &m_xcontext;
  mutable size_t m_count{0};
};

#endif  // X_PROTOCOL_PLUGIN_XPROTOCOL_PLUGIN_H
