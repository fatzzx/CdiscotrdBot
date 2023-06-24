#include "env.h"
#include "commands/all_commands.h"

int main() {
    dpp::cluster bot(BOT_TOKEN);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            handlePingCommand(event);
        } else if (event.command.get_command_name() == "hello"){
            handleHelloCommand(event);
        } else if (event.command.get_command_name() == "author"){
            handleAuthorCommand(event);
        } else if (event.command.get_command_name() == "waifu"){
            handleGeneralWaifuApiCommand(event);
        }
    });

    bot.on_user_context_menu([&](const dpp::user_context_menu_t &event){
        if(event.command.get_command_name() == "High Five"){
            handleHighFiveCommand(event);
        }
    });

    bot.on_message_create([&bot](const dpp::message_create_t& event) {
        if(event.msg.author != bot.me.id){
            handleAnyMessageCommand(event);
        }

    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(
                    dpp::slashcommand("ping", "pong!", bot.me.id)
            );
            bot.global_command_create(
                    dpp::slashcommand("hello", "Say hello to you", bot.me.id)
                    );
            bot.global_command_create(
                    dpp::slashcommand("author", "Displays the author of this bot", bot.me.id)
                    );
            bot.global_command_create(
                    dpp::slashcommand("High Five", "Try", bot.me.id)
                    );
            bot.global_command_create(
                    dpp::slashcommand("waifu", "Random waifu pick", bot.me.id)
                    );
        }
    });

    bot.start(dpp::st_wait);

    return 0;

}