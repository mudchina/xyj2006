//Cracked by Roath
inherit ITEM;

string *names = ({
  "[32mĞ¡ÏºÃ×[m",
  "[32mĞ¡ÓãÃç[m",
  "[36mĞ¡òòò½[m",
  "[35m±´¿Ç[m",
  "[34mĞ¡Óã[m",
  "[33mĞ¡Éß[m",
  "[32mĞ¡ÎÚÔô[m",
  "[31mºìÀğÓã[m",
  "[36m²İÓã[m",
  "[32möóÓã[m",
  "[33m¼»Óã[m",
  "[34möãÓã[m",
  "[1;30mºÚÓã[m",
  "[1;36m½ğÓã[m",
  "[35möõÓã[m",
});

string *ids = ({
    "xiao xiami",
    "xiao yumiao",
    "xiao kedou",
    "bei ke",
    "xiao yu",
    "xiao she",
    "xiao wuzei", 
   "li yu",
    "cao yu",
    "nian yu",
    "ji yu",
    "lian yu",
    "hei yu",
    "jin yu",
    "shi yu",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("unit","Ìõ");
  set("value",100);
  setup();
}
