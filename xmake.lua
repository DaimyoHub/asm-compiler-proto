add_rules("mode.debug", "mode.release")

set_toolchains("gcc")
set_languages("cxx20")

target("tests")
  set_kind("binary")
  add_files("tests/*.cpp")
  add_includedirs("lib/")

  -- add_deps("front", "middle", "back")

  if is_mode("debug") then
    add_defines("DEBUG")
  end

