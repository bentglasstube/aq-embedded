#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "data.h"

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
