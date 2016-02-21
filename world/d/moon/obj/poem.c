// poem.c

inherit ITEM;

void init();
int do_read();

void create()
{
        set_name("¶Ï³¦¼¯", ({"poem","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±¾");
	set("long",
	"Ò»±¾ÊÖ³­µÄ£¢¶Ï³¦¼¯£¢£¬×Ö¼£¾êĞã£¬ÊéÒ³ÉÏÒşÒşÓĞÒ»Ğ©ÀáºÛ£®\n");
        set("value", 500);   
        }
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	string *poem = ({
		"Ç¡Èç·ÉÄñ¾ëÖª»¹£¬å£µ´Àæ»¨ÉîÔº¡£",
		"·÷·÷·çÇ°¶È°µÏã£¬ÔÂÉ«ÇÖ»¨Àä¡£",
		"²»·ÅÓñ»¨·É¶éµØ£¬ÁôÔÚ¹ãº®¹¬ãÚ¡££",
		"°Ñ¾ÆËÍ´º´º²»Óï£¬»Æ»èÈ´ÏÂäìäìÓê¡££",
		"ÓÌ×Ô·çÇ°Æ®ÁøĞõ£¬Ëæ´ºÇÒ¿´¹éºÎ´¦¡£¡£",
		"³î²¡ÏàÈÔ£¬ÌŞ¾¡º®µÆÃÎ²»³É¡£",
		"ØùÁ¢ÉËÉñ£¬ÎŞÄÎÇáº®ÖøÃşÈË¡£",
		"ÂúÔºÂä»¨Á±²»¾í£¬¶Ï³¦·¼²İÔ¶¡£",
		"ÎŞĞ÷¾ëÑ°·¼£¬ÏĞÈ´ÇïÇ§Ë÷¡£",
		"Ğ¡ÔºÏæÁ±ÏĞ²»¾í£¬Çú·¿Öì»§ÃÆ³¤ìç",
		});
	
	me=this_player();

    	if( !this_object()->id(arg) ) return 0;
    	if( me->is_busy() )
        		return notify_fail("ÄãÏÖÔÚÃ¦×ÅÄØ£¬ÄÄÓĞÏĞÇéÒİÖÂÒ÷Ê«...\n");
   	if( me->is_fighting() )
        		return notify_fail("Ì«·çÑÅÁË°É£¿´ò¼ÜÊ±»¹Ò÷Ê«...\n");
	
	if ((me->query("gender") == "ÄĞĞÔ") || !((string)me->query("family/family_name")=="ÔÂ¹¬"))
		return notify_fail("æÏ¶ğµÄË½Îï£¬ÍâÈË¿´²»Ì«ºÃ°É£¡\n");

	if( (int)me->query_skill("literate",1)<40 )
		return notify_fail("ÄãÕÕ×ÅÊ«¼¯Ò¡Í·»ÎÄÔµØºßÁË¼¸¾ä£¬²»¹ıÃ»Ã÷°×ÊÇÉ¶ÒâË¼¡£\n");
	if( (int)me->query_skill("literate",1)>70 )
		return notify_fail("ÄãÔÚÕâ·½ÃæÒÑ¾­ºÜÓĞÔìÒè£¬Õâ±¾Êé²»»áÈÃÄã³¤½ø¶àÉÙ¡£\n");

	sen_cost = 50 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("ÄãÏÖÔÚÍ·ÔÎÄÔÕÍ£¬¸ÃĞİÏ¢ĞİÏ¢ÁË¡£\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")/4+1;
	me->improve_skill("literate", gain);

    	message_vision("$NÇáÇáÌ¾µÀ£º" + poem[random(sizeof(poem))] + "\n", me);
		
	return 1;
}

