#ifndef G4NGPRS_H
#define G4NGPRS_H

/**
 * Reads APN type. Main, Second or from the list
 * 1 - Main, 2 - Secondary, 3 - from List
 */
int GetAPNType(char* command);

/**
 * Returns the command to set the APN type (Main, Secondary, from List). 
 * Return value in the command parameter.
 * 1 - Main, 2 - Secondary, 3 - from List
 * PGRMCT
 */
void SetAPNType(char* command, int apnType);

/**
 * Returns the primary APN.
 * QGPRGMA
 */
char* GetPrimaryAPN(char* command);

/**
 * Returns the command to set the primary APN. Return value in the command parameter.
 */
void SetPrimaryAPN(char* command, char* apn);

/**
 * Returns the primary APN username.
 * QGPRGMU
 */
char* GetPrimaryAPNUsername(char* command);

/**
 * Returns the command to set the primary APN username. Return value in the command parameter.
 */
void SetPrimaryAPNUsername(char* command, char* username);

/**
 * Returns the primary APN password.
 * QGPRGMP
 */
char* GetPrimaryAPNPassword(char* command);

/**
 * Returns the command to set the primary APN password. Return value in the command parameter.
 */
void SetPrimaryAPNPassword(char* command, char* password);

/**
 * Returns the secondary APN.
 * QGPRGSA
 */
char* GetSecondaryAPN(char* command);

/**
 * Returns the command to set the secondary APN. Return value in the command parameter.
 */
void SetSecondaryAPN(char* command, char* apn);

/**
 * Returns the secondary APN username.
 * QGPRGSU
 */
char* GetSecondaryAPNUsername(char* command);

/**
 * Returns the command to set the secondary APN username. Return value in the command parameter.
 */
void SetSecondaryAPNUsername(char* command, char* username);

/**
 * Returns the secondary APN password.
 * QGPRGSP
 */
char* GetSecondaryAPNPassword(char* command);

/**
 * Returns the command to set the secondary APN password. Return value in the command parameter.
 */
void SetSecondaryAPNPassword(char* command, char* password);

/**
 * Returns the packet size
 * QGPRPKS
 */
int GetPacketSize(char* command);

/**
 * Returns the command to set the packet size. Return value in the command parameter.
 */
void SetPacketSize(char* command, int packetSize);

/**
 * Returns the peer for remote server.
 * QGPRGRS
 */
char* GetRemotePeer(char* command);

/**
 * Returns the command to set the peer for the remote server. Return value in the command parameter. 
 */
void SetRemotePeer(char* command, char* peer);

/**
 * Returns the port for remote server.
 * QGPRGRP
 */
char* GetRemotePort(char* command);

/**
 * Returns the command to set the port for the remote server. Return value in the command parameter.
 */
void SetRemotePort(char* command, char* port);

/**
 * Returns the upgrade peer.
 * QGPRGUS
 */
char* GetUpgradePeer(char* command);

/**
 * Returns the command to set the upgrade peer. Return value in the command parameter. 
 */
void SetUpgradePeer(char* command, char* peer);

/**
 * Returns the port for upgrade server.
 * QGPRGUP
 */
char* GetUpgradePort(char* command);

/**
 * Returns the command to set the port for the upgrade server. Return value in the command parameter.
 */
void SetUpgradePort(char* command, char* port);

/**
 * Returns the backup peer.
 * QGPRGBS
 */
char* GetBackupPeer(char* command);

/**
 * Returns the command to set the backup peer. Return value in the command parameter. 
 */
void SetBackupPeer(char* command, char* peer);

/**
 * Returns the port for backup server.
 * QGPRGBP
 */
char* GetBackupPort(char* command);

/**
 * Returns the command to set the port for the backup server. Return value in the command parameter.
 */
void SetBackupPort(char* command, char* port);

#endif

