inherit ITEM;

#include <ansi.h>

void create() {
  set_name("批文",({"pi wen","piwen","wen"}));
  set_weight(10);
  set("unit","张");
  setup();
}
void init() {
  add_action("do_look","look");
}

int do_look(string arg) {
  object me=this_player();

  if (arg!="pi wen" && arg!="piwen" && arg!="wen") return 0;
  write(this_object()->long());
  if (query("target")!=me->query("name")) return 1;
  message_vision(HIR"$N看罢批文，勃然大怒，把批文撕了个粉碎，大叫：“待我去找这个昏王评理！”\n"NOR,me);
  destruct(this_object());
  return 1;
}
