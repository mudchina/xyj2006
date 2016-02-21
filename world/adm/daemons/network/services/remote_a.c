/*
 * File    : remote_a.c
 * Creator : ken@XAJH
 * When    : 98-1-15
 *
 * This protocol is used to send a intermud emote request.
 */
#undef DEBUG


#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

void create() {
	seteuid(ROOT_UID);
	set("channel_id", "ÍøÂ·ÆµµÀ¾«Áé(remote_a)");
}

void incoming_request(mapping info)
{
	object ob;
	string msg;
	mapping minfo;

	if( !ACCESS_CHECK(previous_object())) return;

	minfo = (mapping)DNS_MASTER->query_mud_info(info["NAME"]);
	if (!minfo) return ;

	if (stringp(info["PORTUDP"]) && stringp(info["HOSTADDRESS"])) {
		if (info["NAME"] == Mud_name())	return ;
		if (!DNS_MASTER->dns_mudp(info["NAME"]))
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
		ob = find_player(lower_case(info["SOURCE_ID"]));
		if (!ob) return;

		msg = EMOTE_D->do_emote(ob,lower_case(info["MSG"]),info["TARGET"],4);

#ifdef DEBUG
	CHANNEL_D->do_channel(this_object(), DEBUG, sprintf("%s %s.\n",info["MSG"],info["TARGET"] ));
#endif

		if (!stringp(msg)) {
			CHANNEL_D->do_channel(ob,"sys","error : Nothing get from emoted.c");
			return;
			}

		if(!userp(ob)) return;
		CHANNEL_D->do_channel(ob, info["CHANNEL"],msg,1,1);

	}
}
