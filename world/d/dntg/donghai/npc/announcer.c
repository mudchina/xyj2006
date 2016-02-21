// sgzl
#include <ansi.h>
#define NAME "¶«º£ÁúÍõ"

inherit NPC;

void create()
{
  set_name(NAME, ({"donghai longwang"}));
  set("male", "ÄÐÐÔ");
  set("age", 23);

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
  who->add("dntg/number",1);
  who->set("dntg/donghai","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"Äã¾¹¸ÒÄÃ×ßÎÒÁú¹¬µÄ¶¨º£ÉñÕëÌú£¬¿´ÎÒ²»È¥ÓñµÛÃæÇ°¸æÄã£¡");
  tell_object(who,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+chinese_number(i/4)+"Ìì"+chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save();
}

ÿÿ
