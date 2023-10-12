# 设置cmake最小版本
cmake_minimum_required(VERSION 3.6)

# 设置项目名称
project(Distributed_Cache_System)

# 设置C++标准11
set(CMAKE_CXX_STANDARD 17)

# 设置输出compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(GRPC_LIBS
        absl_bad_any_cast_impl
        absl_bad_optional_access
        absl_bad_variant_access
        absl_base
        absl_city
        absl_civil_time
        absl_cord
        absl_cord_internal
        absl_cordz_functions
        absl_cordz_handle
        absl_cordz_info
        absl_cordz_sample_token
        absl_debugging_internal
        absl_demangle_internal
        absl_examine_stack
        absl_exponential_biased
        absl_failure_signal_handler
        absl_flags
        absl_flags_commandlineflag
        absl_flags_commandlineflag_internal
        absl_flags_config
        absl_flags_internal
        absl_flags_marshalling
        absl_flags_parse
        absl_flags_private_handle_accessor
        absl_flags_program_name
        absl_flags_reflection
        absl_flags_usage
        absl_flags_usage_internal
        absl_graphcycles_internal
        absl_hash
        absl_hashtablez_sampler
        absl_int128
        absl_log_severity
        absl_log_internal_check_op
        absl_log_internal_message
        absl_low_level_hash
        absl_malloc_internal
        absl_periodic_sampler
        absl_random_distributions
        absl_random_internal_distribution_test_util
        absl_random_internal_platform
        absl_random_internal_pool_urbg
        absl_random_internal_randen
        absl_random_internal_randen_hwaes
        absl_random_internal_randen_hwaes_impl
        absl_random_internal_randen_slow
        absl_random_internal_seed_material
        absl_random_seed_gen_exception
        absl_random_seed_sequences
        absl_raw_hash_set
        absl_raw_logging_internal
        absl_scoped_set_env
        absl_spinlock_wait
        absl_stacktrace
        absl_status
        absl_statusor
        absl_str_format_internal
        absl_strerror
        absl_strings
        absl_strings_internal
        absl_symbolize
        absl_synchronization
        absl_throw_delegate
        absl_time
        absl_time_zone
        address_sorting
        cares
        crypto
        gpr
        grpc++
        grpc++_alts
        grpc++_error_details
        grpc++_reflection
        grpc++_unsecure
        grpc
        grpc_plugin_support
        grpc_unsecure
        grpcpp_channelz
        protobuf
        re2
        ssl
        upb
        )

# file(GLOB_RECURSE LIB_ABSL /usr/lib/libabsl_*.so)
# find_library(LIB_ABSL libabsl_*.* /usr/lib)
# find_package(grpc CONFIG REQUIRED)

include_directories(include protos)

add_executable(server main.cpp src/CacheClient.cpp src/CacheServiceImpl.cpp protos/cache_service.pb.cc protos/cache_service.grpc.pb.cc)

target_link_libraries(server ${GRPC_LIBS})