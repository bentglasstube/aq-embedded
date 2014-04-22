#include <stdio.h>
#include <string.h>

static const size_t buffer_size = 65536;
static const char *quest_base = "[0] wants you to [1].";

void generate_quest(char* buffer, const size_t len) {
  char before[len], after[len], middle[4];
  char replace[len];
  char *start, *end;

  strncpy(buffer, quest_base, len);
  printf("%s\n", buffer);

  while (start = strchr(buffer, '[')) {
    end = strchr(buffer, ']');

    if (start == buffer) {
      before[0] = 0;
    } else {
      strncpy(before, buffer, start - buffer);
    }

    strncpy(middle, start + 1, end - start - 1);
    strncpy(after, end + 1, len);

    // TODO get random string
    strncpy(replace, "TEST", len);

    buffer[0] = 0;
    strncat(buffer, before, len);
    strncat(buffer, replace, len - strlen(buffer));
    strncat(buffer, after, len - strlen(buffer));

    printf("%s\n", buffer);
  }
};

int main(int argc, char** argv) {
  char quest[buffer_size];
  generate_quest(quest, buffer_size);
  printf("%s\n", quest);
  return 0;
}
