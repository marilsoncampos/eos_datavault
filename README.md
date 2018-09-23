# eos_datavault

## Introduction

This system stores and retrieves encrypted data on the blockchain and can be extended to include multi-signature contracts.


## Installation

Requirements:
A. Docker installed

B. EOS Hackathon image downloaded.
If not sure run the following command.
>docker pull eosio/eos-dev:v1.2.5

Step 1. Enable the scripts in bin.

Make sure that the scripts on the bin directory are on the path and reacheable from bash.

Step 2. Execute the setup for docker.

cd into scripts directory and run.
. ./setup_dock.sh

This will launch the nodeos and keosd nodes, adds the accounts and keys for the users.

## Execution.

Open html pages inside of the frontend dir.

index.html : master user

query.html: trustee user
