#ifndef __DIRS_H
#define __DIRS_H
#define DIR_SECURE              "/adm"
#define DIR_CLASSES             "/std/class"
#define DIR_RACES               "/std/races"
#define DIR_DB                  DIR_SECURE+"/db"
#define DIR_DATA                DIR_SECURE+"/save"
#define DIR_SECURE_DAEMONS      DIR_SECURE+"/daemon"
#define DIR_ACCOUNTS            DIR_DATA+"/accounts"
#define DIR_BOARDS              DIR_DATA+"/boards"
#define DIR_USERS               DIR_DATA+"/users"
#define DIR_LETTERS             DIR_DATA+"/letters"
#define DIR_POSTAL              DIR_DATA+"/postal"
#define DIR_PACCT              DIR_DATA+"/pacct"
#define DIR_SECURE_DAEMONS_SAVE DIR_DATA+"/daemons"
#define DIR_VOTES               DIR_DATA+"/votes"
#define DIR_FACTIONS            DIR_DATA+"/factions"
#define DIR_AREA_VARS           "/daemon/save/area_vars"

#define DIR_DAEMONS             "/daemon"
#define DIR_DAEMONS_SAVE        DIR_DAEMONS+"/save"
#define DIR_DAEMONS_DATA        DIR_DAEMONS+"/db"

#define DIR_INHERITABLES        "/std"
#define DIR_LIVING_INHERITABLES DIR_INHERITABLES+"/living"
#define DIR_ROOM_INHERITABLES   DIR_INHERITABLES+"/room"
#define DIR_USER_INHERITABLES   DIR_INHERITABLES+"/user"

#define DIR_BACKBONE_OBJECTS    DIR_INHERITABLES+"/obj"

#define DIR_LOGS                "/log"
#define DIR_DEBUG               DIR_LOGS+"/debug"
#define DIR_ERROR_LOGS          DIR_LOGS+"/errors"
#define DIR_PERSONAL_LOGS       DIR_LOGS+"/personal"
#define DIR_REPORTS_LOGS        DIR_LOGS+"/reports"
#define DIR_WATCH_LOGS          DIR_LOGS+"/watch"

#define DIR_DOCS                "/doc"
#define DIR_HELP                DIR_DOCS+"/help"
#define DIR_USER_HELP           DIR_HELP+"/user"

#define DIR_AMBASSADOR_HELP     DIR_HELP+"/ambassador"
#define DIR_AVATAR_HELP         DIR_HELP+"/avatar"
#define DIR_CREATOR_HELP        DIR_HELP+"/creator"
#define DIR_LIBRARY             DIR_DOCS+"/library"
#define DIR_HM_HELP             DIR_HELP+"/hm"

#define DIR_ALIGN_HELP          DIR_USER_HELP+"/alignment"
#define DIR_CLASSES_HELP        DIR_USER_HELP+"/classes"

#define DIR_DEITIES_HELP        DIR_USER_HELP+"/deities"
#define DIR_DOMAINS_HELP        DIR_USER_HELP+"/domains"
#define DIR_FAQ_HELP            DIR_USER_HELP+"/faq"
#define DIR_GUIDELINES_HELP     DIR_USER_HELP+"/guidelines"
#define DIR_LORE_HELP           DIR_USER_HELP+"/lore"
#define DIR_MYSTERIES_HELP      DIR_USER_HELP+"/mysteries"
#define DIR_BLOODLINES_HELP     DIR_USER_HELP+"/bloodlines"
#define DIR_PACTS_HELP          DIR_USER_HELP+"/pacts"
#define DIR_CIRCLES_HELP        DIR_USER_HELP+"/circles"
#define DIR_POLICIES_HELP       DIR_USER_HELP+"/policies"
#define DIR_RACES_HELP          DIR_USER_HELP+"/races"
#define DIR_ROLEPLAYING_HELP    DIR_USER_HELP+"/roleplaying"
#define DIR_RULES_HELP          DIR_USER_HELP+"/rules"
#define DIR_SKILLS_HELP         DIR_USER_HELP+"/skills"

#define DIR_CMDS                "/cmds"
#define DIR_SPELLS              DIR_CMDS+"/spells"
#define DIR_ADMIN_CMDS          DIR_CMDS+"/adm"
#define DIR_LAW_CMDS             DIR_CMDS+"/law"
#define DIR_AMBASSADOR_CMDS     DIR_CMDS+"/ambassador"
#define DIR_CLASS_CMDS          DIR_CMDS+"/skills"
#define DIR_CREATOR_CMDS        DIR_CMDS+"/creator"
#define DIR_GUILD_CMDS          DIR_CMDS+"/guild"
#define DIR_HM_CMDS             DIR_CMDS+"/hm"
#define DIR_AVATAR_CMDS         DIR_CMDS+"/avatar"
#define DIR_MORTAL_CMDS         DIR_CMDS+"/mortal"
#define DIR_RACE_CMDS           DIR_CMDS+"/race"
#define DIR_SYSTEM_CMDS         DIR_CMDS+"/system"
#define DIR_UNDEAD_CMDS         DIR_CMDS+"/undead"
#define DIR_WIZARD_SPLS         DIR_CMDS+"/wizard"
#define DIR_PSION_SPLS         DIR_CMDS+"/psionics"
#define DIR_CLERIC_SPLS         DIR_CMDS+"/priest"
#define DIR_THIEF_CMDS          DIR_CMDS+"/thief"
#define DIR_ASSASSIN_CMDS       DIR_CMDS+"/assassin"
#define DIR_CAV_CMDS            DIR_CMDS+"/cavalier"
#define DIR_FIGHTER_CMDS        DIR_CMDS+"/fighter"
#define DIR_OVER_CMDS              DIR_CMDS+"/over"
#define DIR_BARD_CMDS               DIR_CMDS+"/bard"
#define DIR_PALADIN_CMDS           DIR_CMDS+"/paladin"
#define DIR_ANTI_CMDS		   DIR_CMDS+"/antipaladin"
#define DIR_PROF_CMDS             DIR_CMDS+"/profs"
#define DIR_TUTORIALS           DIR_CMDS+"/tutorials"
#define DIR_FEATS           DIR_CMDS+"/feats"

#define REALMS_DIRS             "/realms"

#define DOMAINS_DIRS            "/d"
#define DIR_STANDARD_DOMAIN     DOMAINS_DIRS+"/standard"

#define CASTLES_DIRS            "/hm"

#define DIR_NEWS                "/news"

#define DIR_TMP                 "/tmp"

#endif /* __DIRS_H */
