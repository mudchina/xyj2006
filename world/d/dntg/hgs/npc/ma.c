// sgzl
#include <ansi.h>
#define NAME "ยํิชหง"

inherit NPC;

void create()
{
  set_name(NAME, ({"ma yuanshuai"}));
  set("male", "ฤะะิ");
  set("age", 23);
  set("long", "าปึปด๓ยํบ๏กฃ\n");
  set("combat_exp", 1000000);
  set("daoxing", 1000000);

  

  set_skill("dodge", 120);
  set_skill("parry", 120);
  set_skill("dragonstep", 120);
  map_skill("dodge", "dragonstep");
  set("force", 900);
  set("max_force", 900);
  set("force_factor", 10);

  setup();
}

void init()
{
  ::init();
}

void announce_success(object who)
{
  int i;

  i = random(500);
//  message_vision (HIY NAME+"ลÜมหนýภดกฃ\n" NOR,who);
  who->add("dntg/number",1);
  who->set("dntg/huaguo","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"ีถมหฐิีผฮารวหฎมฑถดตฤฤงอทฃฌหณภ๛ดณนýด๓ฤึฬ์นฌตฺาปนุฃก");
  command("chat ดำดหฦ฿สฎถþถดพซม้ฝิำฆื๐"+who->query("name")+"ฮชอ๕ฃฌหๆสฑฬýบ๒ต๗วฒฃก");
  tell_object(who,"ฤใำฎตรมห"+chinese_number(3)+"ฤ๊"+chinese_number(i/4)+"ฬ์"+chinese_number((i-(i/4)*4)*3)+"สฑณฝตฤตภะะฃก\n");
  message_vision (HIY NAME+"ตใอทนþัüตฤถิ$NหตตฝฃบีโสวฮารวึฺะึตÜตฤาปตใถ๙ะกาโหผฃฌฒปณษพดาโกฃ\n" NOR,who);
  tell_object(who,"ยํิชหงธ๘ฤใาปธ๖สฏอทลฬืำกฃ\n");
  who->save();
}

void refuse_player(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"อปศปลÜมหนýภด$Nากากอทฃบ"+
                  "ฮารวีýิฺักบ๏อ๕ฃฌรปสยฑ๐ภดตทยากฃ\n" NOR,who);
  message_vision (HIY "หตฐี"+NAME+"ผฑดาดาตฤภ๋ฟชมหกฃ\n" NOR,who);
}

ÿÿ
