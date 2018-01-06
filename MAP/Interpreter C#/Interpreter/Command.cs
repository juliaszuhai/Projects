﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interpreter
{
    abstract class Command
    {
        private String key, description;
        public Command(String key, String description) { this.key = key; this.description = description; }
        public abstract void execute();
        public String getKey() { return key; }
        public String getDescription() { return description; }
    }
}
