// created 6/5/1997 by snowcat
#include <ansi.h>

#define MAXPOSITION 7

inherit ITEM;

void create()
{
  set_name("◊œ ⁄¬º", ({ "zishou lu", "zishou",  "lu" }) );   
  set_weight(10);
  setup();
  set("unit", "Ã˚");
/*
  set("long", @LONG

               —˛≥ÿŒ˜¿»°™°™°™°™°™—˛≥ÿ°™°™°™°™°™—˛≥ÿ∂´¿»
                  £¸              £¸              £¸
                  £¸              £¸              £¸
ª∆œºÕ§            £¸            ÃÏ«¨µÓ            £¸             ÿ—Ã∏Û
  £¸  £‹        æ≈«ßƒÍ        £Ø  £¸  £‹        æ≈«ßƒÍ        £Ø  £¸
◊œœºÕ§°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™µÿ¿§µÓ°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™∂®—Ã∏Û
  £¸  £Ø          £¸          £‹  £¸  £Ø          £¸          £‹  £¸
¬ÃœºÕ§            £¸            ‘∆œÛµÓ            £¸            ºƒ—Ã∏Û
  £¸  £‹        ¡˘«ßƒÍ        £Ø  £¸  £‹        ¡˘«ßƒÍ        £Ø  £¸
∫ÏœºÕ§°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™µ©ÂæµÓ°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™∫Æ—Ã∏Û
  £¸  £Ø          £¸          £‹  £¸  £Ø          £¸          £‹  £¸
«‡œºÕ§            £¸            œ¶“˙µÓ            £¸            –˚—Ã∏Û
  £¸  £‹        »˝«ßƒÍ        £Ø  £¸  £‹        »˝«ßƒÍ        £Ø  £¸
‘ÌœºÕ§°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™–«√·µÓ°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™Û¥Ã“‘∞°™ƒ˛—Ã∏Û
  £¸  £Ø          £¸          £‹  £¸  £Ø          £¸          £‹  £¸
ÀÿœºÕ§            £¸            ≥Ωÿ®µÓ            £¸            ∞≤—Ã∏Û
                  £¸              £¸              £¸
                  £¸              £¸              £¸
                ≤ ∑ÔÃ¸°™°™°™°™°™∑‚…ÒÃ®°™°™°™°™°™Ω¡˙Ã¸
                                  °˜


LONG
  );
*/
  set("long", "");

  setup();
}

void reset_long (object me);

void init()
{
  reset_long (this_object());
}


void reset_long (object me)
{
  int i, j;
  string dir;
  string str;

  if (me->query("long_modified"))
    return;

  me->set("long_modified", 1);

  str = @LONG


                  °‘°‘°‘°‘°‘°‘°‘∑‚…Ò∞Ò°‘°‘°‘°‘°‘°‘°‘
LONG;

  dir = "/d/pantao/";
  for (i = 1; i <= MAXPOSITION; i++)
  {
    string npc = dir + "npc/tian"+sprintf("%d",i);
    string s;
    object ob = find_object(npc);
    if (! ob ||
        ! ob->restore())
      ob = new (npc);
    if (ob &&
        s = ob->query("short"))
    {
      string honor;
      sscanf(s, "%s(%s", honor, s);
      s = ob->query("current_player");
      if (s != "none of us")
      {
        honor = honor + " " + s;
        for (j = strlen(honor); j < 30; j++)
          honor = honor + " ";
        str = str + "                    " + honor + "   \n";
      }
    }
  }
  str = me->query("long") + str +
"                  °‘°‘°‘°‘°‘°‘°‘°‘°‘°‘°‘°‘°‘°‘°‘°‘°‘\n\n";
  me->set("long",str);
}


