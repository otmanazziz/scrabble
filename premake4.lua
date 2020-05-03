solution "scrabble"
  configurations {"debug", "release"}

  configuration {"debug"}
    defines {"DEBUG"}
    if _PREMAKE_VERSION >="5.0" then
      symbols "On"
		else
			flags { "Symbols" }
		end


  configuration {"release"}
		if _PREMAKE_VERSION >="5.0" then
			optimize "speed"
		else
			flags { "OptimizeSpeed" }
		end

  configuration {"linux"}
		buildoptions { "-mtune=native -march=native" }
		buildoptions { "-std=c++11" }
		buildoptions { "-W -Wall -Wextra", "-pipe" }

  configuration {"macosx"}
		buildoptions { "-std=c++11" }

  configuration {"linux", "debug"}
    buildoptions {"-g"}
    linkoptions {"-g"}

-- Ajoutez ici les fichiers supplémentaires que vous créez qui ne contiennent
-- pas de main.

common_files = {
  "src/board.hpp", "src/board.cpp",
  "src/spot.hpp", "src/spot.cpp",
  "src/bonus.hpp", "src/bonus.cpp",
  "src/sac_lettres.hpp", "src/sac_lettres.cpp",
  "src/Lettre.hpp", "src/Lettre.cpp",
  "src/joueur.hpp", "src/joueur.cpp",
  "src/noeud.hpp", "src/noeud.cpp",
  "src/gaddag.hpp", "src/gaddag.cpp",
  "src/etat.hpp", "src/etat.cpp",
  "src/pile.hpp", "src/pile.cpp"
}

-- Pour chaque exécutable que vous souhaitez générer, ajoutez un nouveau projet
-- comme ci-dessous en mentionnant les fichiers supplémentaires nécessaires qui
-- ne sont pas dans la liste common_files, en particulier celui contenant le
-- main.

project "test_board"
  language "c++"
  kind "ConsoleApp"
  targetdir "bin"
  files ( common_files )
  files {"src/test_board.cpp"}
