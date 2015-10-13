#pragma once

void CommandProcessor(char inCommand);

// Directions (N, S, E, W, Up, Down)
void MovementHandler(char inDirection);

// Actions (Take, Press, Use, Examine)
void ActionsHandler(char inAction);

// Show command options
void ShowHelp();