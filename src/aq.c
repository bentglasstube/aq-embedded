#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static const char *quest_base        = "[subject] wants you to [adventure].";

static const char *quest_C[]         = { "B","D","F","G","H","J","K","L","M","N","P","R","S","T","V","W","Wh","Y","Z","Th","Ch","Sh","Zh","[V][c]" };
static const char *quest_V[]         = { "A","A","A","E","E","E","I","I","I","O","O","O","U","U","U","Ae","Ee","Ie","Oe","Ue","Oo","Au","Oi","Ai","Ea" };
static const char *quest_adjective[] = { "powerful","magical","sacred","valuable" };
static const char *quest_adventure[] = { "expose the corruption of [title] [name]","assassinate [title] [name]","steal [item] from [object]","recover [item] from [object]","transport [item] to [place]","hunt down and capture [object]","hunt down and kill [object]","explore [place]","slay [object] and retrieve [item]","slay [object] and destroy [item]","rescue [title] [name] from [object]","investigate a star which fell into [place]","thwart the monstrous plan of [object]","find and explore [place]","discover who is assassinating his peers and why","escort [escort] safely to [place]","recover and destroy [item] from [place]","deliver [item] to [name] in [place]","travel to [place] and retrieve [item]","search [place] for treasure","collect [number] [garbage] from [place]","kill [number] of the nearby [beasts]","travel to [place] and defeat [object]","make peace with the people of [place]","aid the people of [place] against [object]","find out what killed all the [beasts] in [place]" };
static const char *quest_beasts[]    = { "bears","rabbits","deer","fish","birds","wolves","foxes","pigs","boars" };
static const char *quest_c[]         = { "b","d","f","g","h","j","k","l","m","n","p","r","s","t","v","w","z","th","ch","sh","ng" };
static const char *quest_cc[]        = { "","","","","","y","[c]","[c][v]","[c][v]","[c][v][cc]" };
static const char *quest_enemy[]     = { "murderer","scoundrel","thief","scalawag","vandal","cur" };
static const char *quest_escort[]    = { "a caravan of [adjective] goods","a locked chest","his daughter","his son","his family","her daughter","her son","her family" };
static const char *quest_garbage[]   = { "berries","hides","feathers","gemstones","ingots" };
static const char *quest_geo2[]      = { "Tundra","Savannah","Woodlands","Caldera","[geo]" };
static const char *quest_geo[]       = { "Sea","Swamp","Forest","Mountains","Cavern" };
static const char *quest_group[]     = { "warlocks","cultists","theives","traitors" };
static const char *quest_item[]      = { "the Relic of [name]","the Sword of [name]","the Amulet of [name]","a [adjective] device","a [adjective] artifact" };
static const char *quest_modifier[]  = { "shady","wealthy","cryptic","mysterious","dying","disgruntled","hoary","skittish","frantic","mysterious","worried","vacant","crippled","stocky","peg-legged","one-eyed","lecherous","destitute","ghostly" };
static const char *quest_monster[]   = { "Demon","Dragon","Vampire","Goblin","Orc","Troll","Kobold" };
static const char *quest_name[]      = { "[C][v][c][v][cc]" };
static const char *quest_number[]    = { "12","20","25","40","50","75","100","200","250","500","100" };
static const char *quest_object[]    = { "[name], the [monster] [title]","a rival","the [enemy] [name]","the [group] of [name]","the [monster] of [place]","the pirates of the [name] Sea" };
static const char *quest_person[]    = { "aristocrat","dwarf","elf","ex-adventurer","farmer","gnome","mercenary","merchant","peasant","pirate","sage","traveler","vagabond","wizard" };
static const char *quest_place[]     = { "[name] [name]","the [name] [geo2]","the [geo] of [name]","Lake [name]","the town of [name]","the lost city of [name]","the ancient ruins of [name]" };
static const char *quest_subject[]   = { "[title] [name]","A [modifier] [person] named [name]","A [modifier] [person] named [name]" };
static const char *quest_title[]     = { "Lord","Lady","King","Queen","Prince","Princess","Count","Countess","Duke","Dutchess" };
static const char *quest_v[]         = { "a","a","a","e","e","e","i","i","i","o","o","o","u","u","u","ae","ee","ie","oe","ue","oo","au","oi","ai","ea" };

static const size_t buffer_size = 65536;

static inline int rand_int(const int bound) {
  return random() % bound;
}

void generate_quest(char* buffer, const size_t len) {
  char before[len], after[len], middle[len], replace[len];
  char *start, *end;

  strncpy(buffer, quest_base, len);

  while (start = strchr(buffer, '[')) {
    end = strchr(buffer, ']');

    if (start == buffer) {
      before[0] = 0;
    } else {
      strncpy(before, buffer, start - buffer);
      before[start - buffer] = 0;
    }

    strncpy(middle, start + 1, end - start - 1);
    middle[end - start - 1] = 0;

    strncpy(after, end + 1, len);

    if      (strcmp(middle, "beasts")    == 0) strncpy(replace, quest_beasts[rand_int(9)],     len);
    else if (strcmp(middle, "monster")   == 0) strncpy(replace, quest_monster[rand_int(7)],    len);
    else if (strcmp(middle, "object")    == 0) strncpy(replace, quest_object[rand_int(6)],     len);
    else if (strcmp(middle, "number")    == 0) strncpy(replace, quest_number[rand_int(11)],    len);
    else if (strcmp(middle, "title")     == 0) strncpy(replace, quest_title[rand_int(10)],     len);
    else if (strcmp(middle, "C")         == 0) strncpy(replace, quest_C[rand_int(24)],         len);
    else if (strcmp(middle, "name")      == 0) strncpy(replace, quest_name[0],                 len);
    else if (strcmp(middle, "modifier")  == 0) strncpy(replace, quest_modifier[rand_int(19)],  len);
    else if (strcmp(middle, "V")         == 0) strncpy(replace, quest_V[rand_int(25)],         len);
    else if (strcmp(middle, "enemy")     == 0) strncpy(replace, quest_enemy[rand_int(6)],      len);
    else if (strcmp(middle, "subject")   == 0) strncpy(replace, quest_subject[rand_int(3)],    len);
    else if (strcmp(middle, "geo2")      == 0) strncpy(replace, quest_geo2[rand_int(5)],       len);
    else if (strcmp(middle, "garbage")   == 0) strncpy(replace, quest_garbage[rand_int(5)],    len);
    else if (strcmp(middle, "escort")    == 0) strncpy(replace, quest_escort[rand_int(8)],     len);
    else if (strcmp(middle, "group")     == 0) strncpy(replace, quest_group[rand_int(4)],      len);
    else if (strcmp(middle, "c")         == 0) strncpy(replace, quest_c[rand_int(21)],         len);
    else if (strcmp(middle, "geo")       == 0) strncpy(replace, quest_geo[rand_int(5)],        len);
    else if (strcmp(middle, "adjective") == 0) strncpy(replace, quest_adjective[rand_int(4)],  len);
    else if (strcmp(middle, "adventure") == 0) strncpy(replace, quest_adventure[rand_int(26)], len);
    else if (strcmp(middle, "item")      == 0) strncpy(replace, quest_item[rand_int(5)],       len);
    else if (strcmp(middle, "v")         == 0) strncpy(replace, quest_v[rand_int(25)],         len);
    else if (strcmp(middle, "person")    == 0) strncpy(replace, quest_person[rand_int(14)],    len);
    else if (strcmp(middle, "place")     == 0) strncpy(replace, quest_place[rand_int(7)],      len);
    else if (strcmp(middle, "cc")        == 0) strncpy(replace, quest_cc[rand_int(10)],        len);

    buffer[0] = 0;
    strncat(buffer, before, len);
    strncat(buffer, replace, len - strlen(buffer));
    strncat(buffer, after, len - strlen(buffer));
  }
};

int main(int argc, char** argv) {
  srandom(time(NULL));

  char quest[buffer_size];
  generate_quest(quest, buffer_size);
  printf("%s\n", quest);
  return 0;
}
