add_rules("mode.debug", "mode.release")

set_toolchains("gcc")
set_languages("cxx20")


target("tests")
  set_kind("binary")
  add_files("tests/*.cpp")
  add_includedirs("lib/")

  add_deps("front")

  if is_mode("debug") then
    add_defines("DEBUG")
  end


target("front")
  set_kind("static")
  add_files("src/front/*.cpp")
  add_includedirs("lib/")

  if is_mode("debug") then 
    add_defines("DEBUG")
  end

