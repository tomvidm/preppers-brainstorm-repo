names = {
    scandinavian = {
        first_names = {
            male = {
                "Andre",
                "Arne",
                "Atle",
                "Anton",
                "Andreas",
                "Anders",
                "Bjorn",
                "Christian",
                "Christer",
                "David",
                "Daniel",
                "Elias",
                "Erik",
                "Eirik",
                "Endre",
                "Emil",
                "Frank",
                "Filip",
                "Georg",
                "Harald",
                "Henning",
                "Johan",
                "John",
                "Jan",
                "Kristian",
                "Krister",
                "Kurt",
                "Lennart",
                "Ragnar"
            },

            female = {
                "Anna",
                "Anne",
                "Beate",
                "Birgit",
                "Cecilie",
                "Dina",
                "Elise",
                "Elisabeth",
                "Else",
                "Froya",
                "Hilde",
                "Helene",
                "Helena",
                "Herborg",
                "Jorunn",
                "Johanne",
                "Johanna",
                "Marit",
                "Marte",
                "Marta",
                "Marie",
                "Maria",
                "Marianne",
                "Pernille",
                "Ragnhild",
                "Ragna",
                "Silje",
                "Susanne",
                "Sigrid",
                "Sanne",
                "Tove",
                "Tuva",
                "Torunn",
                "Unni",
                "Vilde",
                "Veronika",
                "Aase"
            }
        },

        last_names = {
            "Hansen",
            "Olsen",
            "Sjoflot"
        }
    },

    east_slavic = {
        first_names = {
            male = {
                "Alexandr",
                "Andrey",
                "Anton",
                "Anatoly",
                "Artyom",
                "Bohdan",
                "Dmitry",
                "Denys",
                "Evgeny",
                "Valeriy",
                "Vasily",
                "Nikita",
                "Nikolay",
                "Mikhail",
                "Maksim",
                "Kiril",
                "Piotr",
                "Sergey",
                "Vyacheslav",
                "Vladyslav",
                "Yaroslav",
                "Vitaly",
                "Igor",
                "Vladimir",
                "Ivan",
                "Taras",
                "Tymofey", 
                "Fyodr",
                "Leonid"
            },

            female = {
                "Anna",
                "Alevtyna",
                "Bohdana",
                "Evgeniya",
                "Elena",
                "Elisaveta",
                "Valeriya",
                "Valentina",
                "Ekaterina",
                "Krystyna",
                "Julia",
                "Nadezhda",
                "Svetlana",
                "Ivanna",
                "Olga",
                "Tatyana",
                "Natalya",
                "Varvara",
                "Alysa",
                "Anastaniya",
                "Oksana",
                "Yaroslava",
                "Diana",
                "Alyona",
                "Ludmila"
            }
        },

        last_names = {
            "Poroshenko",
            "Kyrychenko",
            "Yakovenko",
            "Ishchenko",
            "Tkachenko",
            "Tymoshenko",
            "Kondratenko",
            "Komchatnykh",
            "Levitskikh",
            "Aliyev",
            "Belyakov",
            "Bogdanov",
            "Gavrilov",
            "Gorbachev",
            "Yeltsin",
            "Yezhov",
            "Zharkov",
            "Ivchenko",
            "Klimov",
            "Lebedev",
            "Leonidov",
            "Mirov",
            "Morozov"
        }
    }
}

math.randomseed(os.time())

function getRandomFirstName (langGroup, gender)
    fnames = names[langGroup].first_names[gender]
    return fnames[math.random(#fnames)]
end

function getRandomLastName (langGroup)
    lnames = names[langGroup].last_names
    return lnames[math.random(#lnames)]
end

-- print(getRandomFirstName("east_slavic", "male"))
-- print(getRandomLastName("east_slavic"))