use crate::command::{set_color::SetColor, Command};
use clap::{arg, command, Parser, Subcommand};

#[derive(Parser, Debug)]
#[command(version, about)]
pub struct Cli {
    #[command(subcommand)]
    command: Commands,
}

#[derive(Subcommand, Debug)]
pub enum Commands {
    #[command(name = "rgb", about = "Set RGB color using an RGB triplet")]
    SetColorRgb { r: u8, g: u8, b: u8 },
    #[command(name = "hex", about = "Set RGB color using a hex value")]
    SetColorHex {
        #[arg(help = "Hex color value in the format RRGGBB")]
        hex: String,
    },
}

pub fn parse_args() -> anyhow::Result<impl Command> {
    let cli = Cli::parse();

    Ok(match cli.command {
        Commands::SetColorRgb { r, g, b } => SetColor::new(r, g, b),
        Commands::SetColorHex { hex } => {
            // Remove leading '#' if present
            let hex = hex.trim_start_matches('#');

            let r = u8::from_str_radix(&hex[0..2], 16)?;
            let g = u8::from_str_radix(&hex[2..4], 16)?;
            let b = u8::from_str_radix(&hex[4..6], 16)?;
            SetColor::new(r, g, b)
        }
    })
}
