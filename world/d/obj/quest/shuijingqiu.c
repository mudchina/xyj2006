//Cracked by Roath
// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

int do_locate(string arg);
int do_task();

void create()
{
        set_name("Ë®¾§Çò", ({"shuijing qiu","qiu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÒ»¼şÓÃÓÚÑ°ÕÒ¶ªÊ§Îï¼şµÄË®¾§Çò£¬Ëü¾ßÓĞ·Ç·²µÄÄ§Á¦¡£\n"+
                            "ÄÜÓÃ(locate)ÃüÁîÕÒµ½ÎïÆ·µÄ´ó¸ÅÎ»ÖÃ£¡\n");
                set("unit", "¼ş");
                set("value", 300);
        }
}

void init()
{
        object ob = this_player();

  add_action("do_locate","locate");
  add_action("do_task","task");
}

int do_task()
{
   string output;
   output="Ë®¾§ÇòÀïÍ»È»Ó³ÏÖ³öÒ»ÆªÓ¬Í·Ğ¡×Ö£º\n\n"+"/adm/daemons/questd"->dyn_quest_list();
   this_player()->start_more(output);
   return 1;
}

int query_autoload() { return 1; }

int do_locate(string arg)
{
   if ( ! arg)

   return notify_fail("locate <ÎïÆ·>\n");
   else
   "/adm/daemons/questd"->locate_quest(this_player(),arg«É…w)öæ»6o~m#£yôŠ