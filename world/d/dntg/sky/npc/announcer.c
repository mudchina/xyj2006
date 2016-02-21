// sgzl
#include <ansi.h>
#define NAME "ÌìÅîÔªË§"

inherit NPC;

void create()
{
  set_name(NAME, ({"tian peng yuan shuai"}));
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
  command("chat ´óµ¨"+who->query("name")+"£¡Äã²»ºÃºÃ×÷ÄãµÄåöÂíÎÂ£¬È´µ½ÌìºÓÀ´µ·ÂÒ£¬»¹¸ÒµÃ×ïÉÏ¹Ù£¬Äã¸øÎÒ×ß×ÅÇÆ£¡£¡");
  tell_object(who,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+chinese_number(i/4)+"Ìì"+chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀÐÐ£¡\n");
  who->save();
}

ÿÿ
