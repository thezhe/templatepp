#!/usr/bin/env bash
# Create a GitHub release from the current tag and current directory.
# See https://docs.github.com/en/actions/using-workflows/using-github-cli-in-workflows.

gh release create --notes-from-tag *
