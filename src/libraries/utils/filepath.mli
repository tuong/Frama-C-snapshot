(**************************************************************************)
(*                                                                        *)
(*  This file is part of Frama-C.                                         *)
(*                                                                        *)
(*  Copyright (C) 2007-2016                                               *)
(*    CEA (Commissariat à l'énergie atomique et aux énergies              *)
(*         alternatives)                                                  *)
(*                                                                        *)
(*  you can redistribute it and/or modify it under the terms of the GNU   *)
(*  Lesser General Public License as published by the Free Software       *)
(*  Foundation, version 2.1.                                              *)
(*                                                                        *)
(*  It is distributed in the hope that it will be useful,                 *)
(*  but WITHOUT ANY WARRANTY; without even the implied warranty of        *)
(*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *)
(*  GNU Lesser General Public License for more details.                   *)
(*                                                                        *)
(*  See the GNU Lesser General Public License version 2.1                 *)
(*  for more details (enclosed in the file licenses/LGPLv2.1).            *)
(*                                                                        *)
(**************************************************************************)

(** Functions manipulating filepaths.
    In these functions, references to the present working directory refer
    to the result given by function Sys.getcwd. *)

(** Returns an absolute path leading to the given file.
    The result is similar to [realpath --no-symlinks].
    Some special behaviors include:
    - [normalize ""] (empty string) raises [Invalid_argument]
      (realpath returns an error);
    - [normalize] preserves multiple sequential '/' characters,
      unlike [realpath];
    - non-existing directories in [realpath] may lead to ENOTDIR errors,
      but [normalize] may accept them.
    @modify Aluminium-20160501 optional base. *)
val normalize: ?base:string -> string -> string

(** [relativize base file] returns a (strict) relative path of [file]
    w.r.t. [base], if [base] is a prefix of [file]; otherwise,
    returns [file] unchanged.
    The default base is the present working directory.
    @since Aluminium-20160501 *)
val relativize: ?base:string -> string -> string

(** returns true if the file is strictly relative to [base]
    (that is, it is prefixed by [base]), or to the present working directory
    if no base is specified.
    @since Aluminium-20160501 *)
val is_relative: ?base:string -> string -> bool

(** Pretty-print a path according to these rules:
    - relative filenames are kept, except for leading './', which are stripped;
    - absolute filenames are relativized if their prefix is included in the
      present working directory; also, symbolic names are resolved,
      i.e. the result may be prefixed by known aliases (e.g. FRAMAC_SHARE).
      See {!add_symbolic_dir} for more details.
    Therefore, the result of this function may not designate a valid name
    in the filesystem.

    @since Neon-20140301
*)
val pretty: string -> string

(** [add_symbolic_dir name dir] indicates that the (absolute) path [dir] must
    be replaced by [name] when pretty-printing paths.
    This alias ensures that system-dependent paths such as FRAMAC_SHARE are
    printed identically in different machines. *)
val add_symbolic_dir: string -> string -> unit

(*
  Local Variables:
  compile-command: "make -C ../../.."
  End:
*)
