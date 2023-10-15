// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cache_service.proto

#include "cache_service.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
        template <typename>
PROTOBUF_CONSTEXPR Request::Request(::_pbi::ConstantInitialized)
    : _impl_{
      /*decltype(_impl_.req_)*/ {
          &::_pbi::fixed_address_empty_string,
          ::_pbi::ConstantInitialized{},
      },
      /*decltype(_impl_._cached_size_)*/ {},
    } {}
struct RequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR RequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~RequestDefaultTypeInternal() {}
  union {
    Request _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 RequestDefaultTypeInternal _Request_default_instance_;
        template <typename>
PROTOBUF_CONSTEXPR Reply::Reply(::_pbi::ConstantInitialized)
    : _impl_{
      /*decltype(_impl_.reply_)*/ {
          &::_pbi::fixed_address_empty_string,
          ::_pbi::ConstantInitialized{},
      },
      /*decltype(_impl_._cached_size_)*/ {},
    } {}
struct ReplyDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ReplyDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ReplyDefaultTypeInternal() {}
  union {
    Reply _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ReplyDefaultTypeInternal _Reply_default_instance_;
static ::_pb::Metadata file_level_metadata_cache_5fservice_2eproto[2];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_cache_5fservice_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_cache_5fservice_2eproto = nullptr;
const ::uint32_t TableStruct_cache_5fservice_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::Request, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::Request, _impl_.req_),
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::Reply, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::Reply, _impl_.reply_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::Request)},
        {9, -1, -1, sizeof(::Reply)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::_Request_default_instance_._instance,
    &::_Reply_default_instance_._instance,
};
const char descriptor_table_protodef_cache_5fservice_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\023cache_service.proto\"\026\n\007Request\022\013\n\003req\030"
    "\001 \001(\t\"\026\n\005Reply\022\r\n\005reply\030\001 \001(\t2\\\n\014CacheSe"
    "rvice\022\027\n\003Get\022\010.Request\032\006.Reply\022\027\n\003Set\022\010."
    "Request\032\006.Reply\022\032\n\006Delete\022\010.Request\032\006.Re"
    "plyb\006proto3"
};
static ::absl::once_flag descriptor_table_cache_5fservice_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_cache_5fservice_2eproto = {
    false,
    false,
    171,
    descriptor_table_protodef_cache_5fservice_2eproto,
    "cache_service.proto",
    &descriptor_table_cache_5fservice_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_cache_5fservice_2eproto::offsets,
    file_level_metadata_cache_5fservice_2eproto,
    file_level_enum_descriptors_cache_5fservice_2eproto,
    file_level_service_descriptors_cache_5fservice_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_cache_5fservice_2eproto_getter() {
  return &descriptor_table_cache_5fservice_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_cache_5fservice_2eproto(&descriptor_table_cache_5fservice_2eproto);
// ===================================================================

class Request::_Internal {
 public:
};

Request::Request(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Request)
}
Request::Request(const Request& from) : ::google::protobuf::Message() {
  Request* const _this = this;
  (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.req_){},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  _impl_.req_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.req_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_req().empty()) {
    _this->_impl_.req_.Set(from._internal_req(), _this->GetArenaForAllocation());
  }

  // @@protoc_insertion_point(copy_constructor:Request)
}
inline void Request::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.req_){},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _impl_.req_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.req_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}
Request::~Request() {
  // @@protoc_insertion_point(destructor:Request)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Request::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.req_.Destroy();
}
void Request::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

PROTOBUF_NOINLINE void Request::Clear() {
// @@protoc_insertion_point(message_clear_start:Request)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.req_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Request::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 19, 2> Request::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Request_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // string req = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Request, _impl_.req_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string req = 1;
    {PROTOBUF_FIELD_OFFSET(Request, _impl_.req_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\7\3\0\0\0\0\0\0"
    "Request"
    "req"
  }},
};

::uint8_t* Request::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Request)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string req = 1;
  if (!this->_internal_req().empty()) {
    const std::string& _s = this->_internal_req();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Request.req");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Request)
  return target;
}

::size_t Request::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Request)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string req = 1;
  if (!this->_internal_req().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_req());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData Request::_class_data_ = {
    ::google::protobuf::Message::CopyWithSourceCheck,
    Request::MergeImpl
};
const ::google::protobuf::Message::ClassData*Request::GetClassData() const { return &_class_data_; }


void Request::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<Request*>(&to_msg);
  auto& from = static_cast<const Request&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Request)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_req().empty()) {
    _this->_internal_set_req(from._internal_req());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Request::CopyFrom(const Request& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Request)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Request::IsInitialized() const {
  return true;
}

void Request::InternalSwap(Request* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.req_, lhs_arena,
                                       &other->_impl_.req_, rhs_arena);
}

::google::protobuf::Metadata Request::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_cache_5fservice_2eproto_getter, &descriptor_table_cache_5fservice_2eproto_once,
      file_level_metadata_cache_5fservice_2eproto[0]);
}
// ===================================================================

class Reply::_Internal {
 public:
};

Reply::Reply(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:Reply)
}
Reply::Reply(const Reply& from) : ::google::protobuf::Message() {
  Reply* const _this = this;
  (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.reply_){},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  _impl_.reply_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.reply_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_reply().empty()) {
    _this->_impl_.reply_.Set(from._internal_reply(), _this->GetArenaForAllocation());
  }

  // @@protoc_insertion_point(copy_constructor:Reply)
}
inline void Reply::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.reply_){},
      /*decltype(_impl_._cached_size_)*/ {},
  };
  _impl_.reply_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.reply_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}
Reply::~Reply() {
  // @@protoc_insertion_point(destructor:Reply)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Reply::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.reply_.Destroy();
}
void Reply::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

PROTOBUF_NOINLINE void Reply::Clear() {
// @@protoc_insertion_point(message_clear_start:Reply)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.reply_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* Reply::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 19, 2> Reply::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Reply_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    // string reply = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Reply, _impl_.reply_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string reply = 1;
    {PROTOBUF_FIELD_OFFSET(Reply, _impl_.reply_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\5\5\0\0\0\0\0\0"
    "Reply"
    "reply"
  }},
};

::uint8_t* Reply::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Reply)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string reply = 1;
  if (!this->_internal_reply().empty()) {
    const std::string& _s = this->_internal_reply();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "Reply.reply");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Reply)
  return target;
}

::size_t Reply::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Reply)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string reply = 1;
  if (!this->_internal_reply().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_reply());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData Reply::_class_data_ = {
    ::google::protobuf::Message::CopyWithSourceCheck,
    Reply::MergeImpl
};
const ::google::protobuf::Message::ClassData*Reply::GetClassData() const { return &_class_data_; }


void Reply::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<Reply*>(&to_msg);
  auto& from = static_cast<const Reply&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Reply)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_reply().empty()) {
    _this->_internal_set_reply(from._internal_reply());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Reply::CopyFrom(const Reply& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Reply)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool Reply::IsInitialized() const {
  return true;
}

void Reply::InternalSwap(Reply* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.reply_, lhs_arena,
                                       &other->_impl_.reply_, rhs_arena);
}

::google::protobuf::Metadata Reply::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_cache_5fservice_2eproto_getter, &descriptor_table_cache_5fservice_2eproto_once,
      file_level_metadata_cache_5fservice_2eproto[1]);
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
