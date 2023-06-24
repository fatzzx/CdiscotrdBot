//
// Created by fatzzx on 23/06/23.
//

#ifndef DISCORD_BOT_AUTHOR_H
#define DISCORD_BOT_AUTHOR_H

#include "discord_bot.h"

void handleAuthorCommand(const dpp::slashcommand_t& event){

    dpp::embed embed = dpp::embed()
            .set_color(dpp::colors::sti_blue)
            .set_title("Fatzzx")
            .set_image("https://avatars.githubusercontent.com/u/112991044?v=4")
            .set_footer(dpp::embed_footer().set_text("Time ").set_icon("https://avatars.githubusercontent.com/u/112991044?v=4")).set_timestamp(time(0));

    dpp::message message(event.command.channel_id, embed);
    event.reply(message);

}

#endif //DISCORD_BOT_AUTHOR_H
