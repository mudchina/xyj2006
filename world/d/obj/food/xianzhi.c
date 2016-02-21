// xianzhi.c        

inherit ITEM;
inherit F_LIQUID;

void create()
{
  string *names = ({
    "Çí½¬",
    "ÓñÒº",
    "õ®õ­",
    "ÑşÂ¶",
    });
  string *ids = ({
    "qiong jiang",
    "yu ye",
    "ti hu",
    "yao lu",
    });
  int i = random(4);

  set_name(names[i],({ids[i]}));
  set_weight(300);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "Óñºø");
    set("value", 10000);
    set("max_liquid", 5000);
    set("no_get",1);
    set("no_drop",1);
    set("no_sell",1);
  }
  set("liquid", ([
        "type": "wine",
        "name": names[i],
        "remaining": 5000,
        "drunk_apply": 10,
     ]));
  set("long", "Ò»ÓñºøÌìÉÏ²ÅÓĞµÄÏÉÖ­Õæ¾Æ£­£­"+names[i]+"¡£\n");
  setup();
}

