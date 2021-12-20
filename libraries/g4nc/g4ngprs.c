#include <stdlib.h>
#include "g4ngprs.h"

int GetAPNType(char* command) {
	char* apnTypeStr = substring(command, 7, 11);
	int apnType = parseInt(apnTypeStr, 16);
	free(apnTypeStr);
	switch(apnType & 0x3000) {
		case 0x0000: return 1; /* Main apn */
		case 0x1000: return 3; /* from list */
		case 0x2000: return 2; /* Secondary apn */
	}
	return 0;
}

void SetAPNType(char* command, int apnType) {
	strcat(command, "PGPRMCT");
	switch(apnType) {
		case 1:
			strcat(command, "0000//");
			break;
		case 2:
			strcat(command, "2000//");
			break;
		case 3:
			strcat(command, "1000//");
			break;
	}
	return;
}

char* GetPrimaryAPN(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

void SetPrimaryAPN(char* command, char* apn) {
	strcat(command, "PGPRGMA");
	strcat(command, apn);
	strcat(command, "//");
	return;
}

char* GetPrimaryAPNUsername(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

void SetPrimaryAPNUsername(char* command, char* username) {
	strcat(command, "PGPRGMU");
	strcat(command, username);
	strcat(command, "//");
	return;
}

/* QGPRGMP */
char* GetPrimaryAPNPassword(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

/* Returns the command to set the primary APN password */
void SetPrimaryAPNPassword(char* command, char* password) {
	strcat(command, "PGPRGMP");
	strcat(command, password);
	strcat(command, "//");
	return;
}

/* QGPRGSA */
char* GetSecondaryAPN(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

void SetSecondaryAPN(char* command, char* apn) {
	strcat(command, "PGPRGSA");
	strcat(command, apn);
	strcat(command, "//");
	return;
}

/* QGPRGSU */
char* GetSecondaryAPNUsername(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

void SetSecondaryAPNUsername(char* command, char* username) {
	strcat(command, "PGPRGSU");
	strcat(command, username);
	strcat(command, "//");
	return;
}

/* QGPRGSP */
char* GetSecondaryAPNPassword(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

void SetSecondaryAPNPassword(char* command, char* password) {
	strcat(command, "PGPRGSP");
	strcat(command, password);
	strcat(command, "//");
	return;
}

/* QGPRPKS */
int GetPacketSize(char* command) {
	return parseInt(substring(command, 7, indexOf(command, "//")), 16);
}

void SetPacketSize(char* command, int packetSize) {
	char s[20] = "";
	toHexaString(s, packetSize, 4);
	strcat(command, "PGPRPKS");
	strcat(command, s);
	strcat(command, "//");
	return;
}

/**
 * Returns the peer for remote server.
 * QGPRGRS
 */
char* GetRemotePeer(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

/**
 * Returns the command to set the peer for the remote server. Return value in the command parameter.
 */
void SetRemotePeer(char* command, char* peer) {
	strcat(command, "PGPRGRS");
	strcat(command, peer);
	strcat(command, "//");
	return;
}

/**
 * Returns the port for remote server.
 * QGPRGRP
 */
char* GetRemotePort(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

/**
 * Returns the command to set the port for the remote server. Return value in the command parameter.
 */
void SetRemotePort(char* command, char* port) {
	strcat(command, "PGPRGRP");
	strcat(command, port);
	strcat(command, "//");
	return;
}

/**
 * Returns the upgrade peer.
 * QGPRGUS
 */
char* GetUpgradePeer(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

/**
 * Returns the command to set the upgrade peer. Return value in the command parameter.
 */
void SetUpgradePeer(char* command, char* peer) {
	strcat(command, "PGPRGUS");
	strcat(command, peer);
	strcat(command, "//");
	return;
}

/**
 * Returns the port for upgrade server.
 * QGPRGUP
 */
char* GetUpgradePort(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

/**
 * Returns the command to set the port for the upgrade server. Return value in the command parameter.
 */
void SetUpgradePort(char* command, char* port) {
	strcat(command, "PGPRGUP");
	strcat(command, port);
	strcat(command, "//");
	return;
}

/**
 * Returns the backup peer.
 * QGPRGBS
 */
char* GetBackupPeer(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

/**
 * Returns the command to set the backup peer. Return value in the command parameter.
 */
void SetBackupPeer(char* command, char* peer) {
	strcat(command, "PGPRGBS");
	strcat(command, peer);
	strcat(command, "//");
	return;
}

/**
 * Returns the port for backup server.
 * QGPRGBP
 */
char* GetBackupPort(char* command) {
	return substring(command, 7, indexOf(command, "//"));
}

/**
 * Returns the command to set the port for the backup server. Return value in the command parameter.
 */
void SetBackupPort(char* command, char* port) {
	strcat(command, "PGPRGBP");
	strcat(command, port);
	strcat(command, "//");
	return;
}
