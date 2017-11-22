-- This lua file defines a lua table containing a list of traits
-- and function simplifying getting information about these
-- from C++

traits = {
    {
        id = "antiintellectual", title = "Anti-Intellectual", 
        description = "Really dislikes know-it-alls.",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "snob", title = "Snob", 
        description = "This person is an annoying snob.",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "cheerful", title = "Cheerful", 
        description = "This person is cheerful and smiles too much.",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "pedantic", title = "Pedantic", 
        description = "Believes academic rigour must apply to even the most mundane things.",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "gluttonous", title = "Gluttonous", 
        description = "Unhealthy appetite!",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "hypochondriac", title = "Hypochondriac", 
        description = "'It's not diarrhea! It's AIDS!'",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "temperate", title = "Temperate", 
        description = "This person will not eat all the food supplies.",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "hippie", title = "Hippie", 
        description = "Too young to remember Woodstock, but still can't stop talking about it.",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "introvert", title = "Introvert", 
        description = "Too young to remember Woodstock, but still can't stop talking about it.",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "extrovert", title = "Introvert", 
        description = "Too young to remember Woodstock, but still can't stop talking about it.",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "jovial", title = "Jovial", 
        description = "This person is very jovial.",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "irritable", title = "Irritable", 
        description = "This person is irritable and tense.",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },

    {
        id = "bright", title = "Bright", 
        description = "While not a genius, this person learns quickly.",
        opinion_of_trait = {
            { "intellectual", -10 }
        }
    },
}

function getNumTraits ()
    return #traits
end

function getTraitTitle (index)
    return traits[index].title
end

function getTraitDescription (index)
    return traits[index].description
end

function getNumTraitOpinions (index)
    return #traits[index].opinion_of_trait
end

function getTraitOpinion (index, opinion)
    return traits[index].opinion_of_trait[opinion][1]
end

function getTraitOpinionModifier (index, opinion)
    return traits[index].opinion_of_trait[opinion][2]
end